
!!! a)
! acceso ping pc1,2,3 server produccion
! RA
access-list 101 permit icmp any host 172.16.10.5
access-list 101 permit tcp any eq 80 host 172.16.10.5 

! acceso ping pc1,2,3 a server pruebas
! RA
access-list 101 permit icmp any host 172.16.10.100
access-list 101 permit tcp any eq 80 host 172.16.10.100

!!! b)

! negación web becarios a server pruebas
! RA
access-list 101 deny tcp host 192.168.0.150 eq 80 host 172.16.10.100

!!! c)

! negación ping laptop sitio 1 a ambos servers
! RA
access-list 101 deny icmp host 192.168.0.5 host 172.16.10.5
access-list 101 deny icmp host 192.168.0.5 host 172.16.10.100

int vlan2
ip access-group 101 in


!!! d)

! negación de todo menos en la misma red

access-list 101 permit icmp any host 172.16.10.5
access-list 101 permit icmp any host 172.16.10.100
access-list 101 permit tcp any eq 80 host 172.16.10.100
access-list 101 permit tcp any eq 80 host 172.16.10.5

! permitir a servidores salir
access-list 101 permit icmp host 172.16.10.100 any
access-list 101 permit icmp host 172.16.10.5 any

access-list 101 permit tcp host 172.16.10.100 eq 80 any
access-list 101 permit tcp host 172.16.10.5 eq 80 any

int vlan2
ip access-group 101 in

