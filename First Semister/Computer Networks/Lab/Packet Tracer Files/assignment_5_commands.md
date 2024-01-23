# first command to show the ip routes is

`show ip route`
make sure you are in the # shell in the router.
then do
conf t
router rip
ver 1
network 10.0.0.0
network 11.0.0.0

then do the same thing in the other router.

for eigrp
no router rip
router eigrp 1
network 12.0.0.0
network 11.0.0.0

11 is the network of the routers. 10 would be the networks on the left and 12 would be the networks on the right.
or anything that you want it to be.

# you might want to try other routing protocols

basic steps are:

1. find a switch, then connect it to pcs, and stuff, assign their ips according to that network family.
2. Do that 2 or 3 times with however many switch networks you want the router to connect
3. Then connect a router to the switches, in the gigabit ethernet port. Then connnec tthe routhers with each other using the serial port, which you will have to install in the router, by first switching it off, and then adding nim 2t port or any port that has a serial port to it. Then switch it on.
4. Now assign the ip addresses to the router. You would have to assign an ip of the family to which it is connected to the port where you are connecting that network like gigabit ethernet or soemthing.
5. Now assign the ip for the router network. set clock to the same as the one that is on the other router. use a clocked red serial cable to connect the 2 routers.
6. Now all the things must be on.

# OSPF Routing protocal // open shortest path first

More commands :
`router> enable` // to enable the router
`router# show ip route` // to show the ip stuff and information

// it looks like this  
Router#show ip route
Codes: L - local, C - connected, S - static, R - RIP, M - mobile, B - BGP
D - EIGRP, EX - EIGRP external, O - OSPF, IA - OSPF inter area
N1 - OSPF NSSA external type 1, N2 - OSPF NSSA external type 2
E1 - OSPF external type 1, E2 - OSPF external type 2, E - EGP
i - IS-IS, L1 - IS-IS level-1, L2 - IS-IS level-2, ia - IS-IS inter area \* - candidate default, U - per-user static route, o - ODR
P - periodic downloaded static route

Gateway of last resort is not set

     10.0.0.0/8 is variably subnetted, 2 subnets, 2 masks

C 10.0.0.0/8 is directly connected, GigabitEthernet0/0/0
L 10.0.0.3/32 is directly connected, GigabitEthernet0/0/0
12.0.0.0/8 is variably subnetted, 2 subnets, 2 masks
C 12.0.0.0/8 is directly connected, Serial0/2/0
L 12.1.1.2/32 is directly connected, Serial0/2/0

`router# config t` // or configure terminal

Router#
Router#config t
Enter configuration commands, one per line. End with CNTL/Z.
Router(config)#
Router(config)#router ospf ?
<1-65535> Process ID
Router(config)#router ospf 1
Router(config-router)#network 10.0.0.0
% Incomplete command.
Router(config-router)#network 10.0.0.0 0.255.255.255 area 0
Router(config-router)#network 11.0.0.0 0.255.255.255 area 0
Router(config-router)#
Router#
