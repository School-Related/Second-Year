from audioop import reverse
from codecs import getdecoder
from mailbox import NotEmptyError
from os import getpid
from unittest import result
import pandas as pd
import numpy as np

ip_classes = {
    'A' : [8, 24, 126],
    'B' : [16, 16, 191],
    'C' : [24, 8, 223]
}

def get_dec_in_bin_bits(decimal_val, how_many_bits):
    '''
    Returns the given value as <how_many_bits> binary bits as a list of 1s or 0s
    '''
    octet = [0 for i in range(how_many_bits)]
    i = how_many_bits - 1
    while(decimal_val != 0):
        rem = decimal_val % 2
        decimal_val = decimal_val // 2
        octet[i] = rem
        i-=1
    return octet

def get_ip_class(ip):
    '''
    Gets the Class of the IP Address
    '''
    for i in ip:
        if i <= ip_classes['A'][2]:
            return 'A'
        elif i <= ip_classes['B'][2]:
            return 'B'
        elif i <= ip_classes['C'][2]:
            return 'C'

def find_subnet_bits(subnet_number):
    '''
    Returns the Required Number of Subnet bits to Borrow from the host. 
    '''
    for i in range(10):
        if pow(2, i) >= subnet_number:
            return i

def calc_subnet_mask(cidr):
    '''
    Returns the Subnet Mask as a string
    '''
    temp = [[], [], [], []]
    subnet_masks = []
    divs = cidr // 8
    net_bits = cidr % 8
    val = 0

    # Makes everything 1 till divs
    for i in range(4):
        for j in range(8):
            if i <= divs:
                temp[i].append(1)
            else: temp[i].append(0)

    # Makes the important things 1
    for i in range(8):
        if i < net_bits:
            temp[divs][i] = 1
        else: temp[divs][i] = 0       
                    
    return get_ip(temp)

def get_ip(ip_list):
    '''
    Input : A list containing 4 lists, each having 8 int values, 0 or 1
    Output: The Familiar IP Addr string
    '''
    
    ip = []
    
    for i in range(4):
        val = 0
        # Calc decimal value from binary
        for j, _ in zip(ip_list[i], range(8)):
            if j:
                val += pow(2, (7 - _))
        ip.append(str(val))
        
    return '.'.join(ip)
    
def main():
    
    given_ip = []
    # s = '205.16.37.24'
    # s = '172.20.15.1'
    s = '192.168.1.0'
    subnet_number = 32
    
    
    # Input from user. 
    print('Enter the Given IP Address: ')
    # s = input()
    
    print('Enter the Number of Subnets you Want to make: ')
    # subnet_number = int(input())
    
        
    given_ip = [int(i) for i in s.split('.')]
    given_ip_in_bits = [get_dec_in_bin_bits(i, 8) for i in given_ip]
    
    ip_class = get_ip_class(given_ip)
    const_ip_part = given_ip_in_bits[:int(ip_classes[ip_class][0] / 8)]
    
    subnet_bits = find_subnet_bits(subnet_number);
    host_bits = ip_classes[ip_class][1] - subnet_bits
    
    if subnet_bits > ip_classes[ip_class][1]:
        print("Cant Borrow ", subnet_bits, "Number of bits from the host, not enough host bits remaining in class ", ip_class) 
    
    cidr = ip_classes[ip_class][0] + subnet_bits
    possible_subnets = pow(2, subnet_bits)
    possible_hosts = pow(2, host_bits)
    subnet_mask = calc_subnet_mask(cidr)
     
    # Add things to the Dataframe
    df = pd.DataFrame(columns=['Subnet IP', 'Starting Host IP', 'Last Host IP', 'Broadcast IP', 'Subnet Mask'])
    
    data = {
        'Subnet IP' : 0, 
        'Starting Host IP' : 0,
        'Last Host IP': 0,
        'Broadcast IP' : 0,
        'Subnet Mask' : subnet_mask
    }
    
    

    for i in range(possible_subnets):
        # to get the respective ips,we first need the subnet ip
        # there are only possible_subnets possible subnets, so we could just iterate through i

        # Get the subnet part and the host part in bits which will be different each iteratiion of this loop. 
        subnet_part = get_dec_in_bin_bits(i, subnet_bits)
        host_part = get_dec_in_bin_bits(1, host_bits)
        
        # Creating Copies of the Constant part of the IP Address to append to. 
        subnet_ip = const_ip_part[:]
        starting_host_ip = const_ip_part[:]
        last_host_ip = const_ip_part[:]
        broadcast_ip = const_ip_part[:]

        # Appending the Varying part to the constant part for each required arguement. 
        subnet_ip.append(subnet_part + get_dec_in_bin_bits(0, host_bits))
        starting_host_ip.append(subnet_part + get_dec_in_bin_bits(1, host_bits))
        last_host_ip.append(subnet_part + get_dec_in_bin_bits(possible_hosts - 2, host_bits))
        broadcast_ip.append(subnet_part + get_dec_in_bin_bits(possible_hosts - 1, host_bits))

        # Adding the values to the dictionary keys. 
        data['Subnet IP'] = get_ip(subnet_ip)
        data['Starting Host IP'] = get_ip(starting_host_ip)
        data['Last Host IP'] = get_ip(last_host_ip)
        data['Broadcast IP'] = get_ip(broadcast_ip)
        
        # Appending Values to the DataFrame
        df_dictionary = pd.DataFrame([data])
        df = pd.concat([df, df_dictionary], ignore_index=True)
    
    df.to_csv("output.csv")
    
    print()
    print("The IP Address you have entered is: ", given_ip)
    print("Subnet Number: ", subnet_number)
    print("Subnet Bits: ", subnet_bits)
    print("CIDR Value: ", cidr)
    print("Maximum Possible Subnets: ", possible_subnets)
    print("Maxixmum Possible Hosts: ", possible_hosts)
    print("Subnet Mask is: ", subnet_mask)
    
main()
