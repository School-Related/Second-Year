# first command to show the ip routes is 
`show ip route`
make sure you are in the # shell in the router. 
then do 
conf t
router rip
ver 
network 10.0.0.0
network 11.0.0.0

then do the same thing in the other router. 

for eigrp
no router rip
router eigrp 1
network 12.0.0.0
network 11.0.0.0

11 is the network of the routers. 10 would be the networks on the left and 12 would be the networks on the right. 