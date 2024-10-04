
!!!!!!!!!!!!!!!!!!!!
!!! cdmx

! ospf
router ospf 1
router-id 20.20.20.20
passive-interface default
no passive-interface se 0/3/0
exit

int se 0/3/0
ip ospf 1 area 51
exit
int gi 0/0
ip ospf 1 area 51
exit
int gi 0/0.10
ip ospf 1 area 51
exit
int gi 0/0.20
ip ospf 1 area 51
exit

end
wr

!!!!!!!!!!!!!!!!!!!!
!!! toronto

! ospf
router ospf 1
router-id 10.10.10.10
passive-interface default
no passive-interface se 0/3/0
no passive-interface se 0/3/1
exit

int se 0/3/0
ip ospf 1 area 51
exit
int se 0/3/1
ip ospf 1 area 0
exit
int gi 0/0
ip ospf 1 area 0
exit

end 
wr

!!!!!!!!!!!!!!!!!!!!
!!! ohio

! ip addresses int
conf t

! int a switch
int gi 0/1
ip address 10.10.0.1 255.255.0.0
no shutdown
end

show ip int br

! ospf
router ospf 1
router-id 100.100.100.100
passive-interface default
no passive-interface se 0/3/1
no passive-interface gi 0/1
exit

int se 0/3/1
ip ospf 1 area 0
exit
int gi 0/0
ip ospf 1 area 0
exit
int gi 0/1
ip ospf 1 area 69
exit

!!!!!!!!!!!!!!!!!!!!
!!! pachuca

! ip addresses int

conf t

! int a switch
int gi 0/0
ip address 10.10.0.4 255.255.0.0
no shutdown
exit

! int a computadora
int gi 0/1
ip address 192.168.9.1 255.255.255.0
no shutdown
end

show ip int br

! ospf
router ospf 1
router-id 40.40.40.40
passive-interface default
no passive-interface gi 0/0
exit

int gi 0/1
ip ospf 1 area 69
int gi 0/0
ip ospf 1 area 69
exit

end
wr

!!!!!!!!!!!!!!!!!!!!
!!! hum

! ospf
router ospf 1
router-id 90.90.90.90
passive-interface default
no passive-interface gi 0/0
exit

int gi 0/1
ip ospf 1 area 69
exit
int gi 0/0
ip ospf 1 area 69
exit

end
wr

!!!!!!!!!!!!!!!!!!!!
!!! hermosillo

! ospf
router ospf 1
router-id 50.50.50.50
passive-interface default
no passive-interface gi 0/0
exit

int gi 0/1
ip ospf 1 area 69
exit
int gi 0/0
ip ospf 1 area 69
exit

end
wr
