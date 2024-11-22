
!!!! SW 1
int g 1/0/1
switchport mode access
switchport port-security 
switchport port-security maximum 2
exit

int g 1/0/2
switchport mode access
switchport port-security 
switchport port-security mac-address sticky
exit

int range g 1/0/3
switchport mode access
switchport port-security 
switchport port-security violation protect
switchport port-security mac-address sticky
exit

int range g 1/0/4
switchport mode access
switchport port-security 
switchport port-security violation restrict
switchport port-security mac-address sticky
exit

!! R1
!! NAT PAT ganso

access-list 1 permit 192.168.0.0 0.0.0.255
ip nat inside source list 1 interface gi0/0/0 overload 

int gi 0/0/1
ip nat inside
exit

int gi 0/0/0
ip nat outside
exit

!!!! SW 2

int gi 1/0/2
switchport mode access
switchport port-security 
switchport port-security 
switchport port-security maximum 2
exit

int gi 1/0/3
switchport mode access
switchport port-security 
switchport port-security mac-address sticky
exit

int gi 1/0/4
switchport mode access
switchport port-security 
switchport port-security mac-address sticky
switchport port-security violation shutdown
exit

int gi 1/0/5
switchport mode access
switchport port-security 
switchport port-security mac-address sticky
switchport port-security violation protect
exit



show port-se int gi 1/0/3

