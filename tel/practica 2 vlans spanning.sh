en 
configure ternimal
hostname SW_PEPE
vlan 10
name SHADY10
vlan 20
name SHADY20
exit
exit
show vlan brief
configure terminal
interface  fa0/10
switchport mode access
switchport access vlan 10
interface fa0/11

switchport mode access
switchport access vlan 20
exit
exit
show vlan brief

configure terminal
interface fa0/3
switchport mode trunk

en 
configure terminal
hostname SHADY_MK
vlan 10
name SHADY10
vlan 20
name SHADY20
exit
exit
configure terminal
interface fa0/3
switchport mode trunk
interface fa0/4
switchport mode trunk

en
configure terminal
interface Gi0/1
switchport mode trunk

interface Gi0/2
switchport mode trunk

------------------------------------------
en
configure terminal
spanning-tree vlan 10 priority 4096
spanning-tree vlan 1 root primary
spanning-tree vlan 20 priority 4096


spanning-tree mode rapid-pvst

en
configure terminal
interface gigabitEthernet 0/0.10
ip address 192.168.1.1 255.255.255.0
encapsulation dot1Q 10

interface gigabitEthernet 0/0.20
ip address 192.168.2.1 255.255.255.0
encapsulation dot1Q 20

interface gigabitEthernet 0/0.1
exit

interface gigabitEthernet 0/0
no shutdown
exit
exit

show ip interface brief


en
configure terminal
ip default-gateway 192.168.0.1
interface vlan 1
ip address 192.168.0.5 255.255.255.0
no shutdown



wr
reload
```
#TAREA 3

#switches
en
configure terminal
ip default-gateway 192.168.0.1
interface vlan 1
ip address 192.168.0.x 255.255.255.0 #camibar x por el numero de switch no usar 1
no shutdown

#router
en
configure terminal
interface gigabitEthernet 0/0.1
encapsulation dot1Q 1 native
ip address 192.168.0.1 255.255.255.0
no shutdown


#ETHER CHANNEL

#switches
en 
configure terminal
interface range fa0/1 - 2
channel-group 1 mode active
exit
interface port-channel 1
switchport mode trunk

show etherchannel summary




============================
! DIST-SW1	

enable
configure terminal

hostname DIST-SW1	
ip domain-name up.edu.mx

! Configuración de la interfaz VLAN 10
interface vlan 10
ip address 192.168.10.20 255.255.255.0 
no shutdown

! Configuración del Default Gateway
ip default-gateway 192.168.10.1

! Creación del usuario con contraseña hasheada
username parcial1 secret cisco123

! Configuración del modo EXEC privilegiado
enable secret cisco

! Configuración de las llaves crypto
crypto key generate rsa 
  ! Cuando pregunte si desea reemplazar las llaves, responde "yes"

! Configuración de la versión 2 de SSH
ip ssh version 2

! Configuración de las líneas vty 0 a 15 para que solo usen SSH
line vty 0 15
transport input ssh
login local
exec-timeout 0 0      
logging synchronous   
exit


============================
! DIST-SW2	

enable
configure terminal

hostname DIST-SW2	
ip domain-name up.edu.mx

! Configuración de la interfaz VLAN 10
interface vlan 10
ip address 192.168.10.21 255.255.255.0 
no shutdown

! Configuración del Default Gateway
ip default-gateway 192.168.10.1

! Creación del usuario con contraseña hasheada
username parcial1 secret cisco123

! Configuración del modo EXEC privilegiado
enable secret cisco

! Configuración de las llaves crypto
crypto key generate rsa 
  ! Cuando pregunte si desea reemplazar las llaves, responde "yes"

! Configuración de la versión 2 de SSH
ip ssh version 2

! Configuración de las líneas vty 0 a 15 para que solo usen SSH
line vty 0 15
transport input ssh
login local
exec-timeout 0 0      
logging synchronous   
exit



=====================
! ACC-SW1

enable
configure terminal

hostname ACC-SW1
ip domain-name up.edu.mx

! Configuración de la interfaz VLAN 10
interface vlan 10
ip address 192.168.10.22 255.255.255.0 
no shutdown

! Configuración del Default Gateway
ip default-gateway 192.168.10.1

! Creación del usuario con contraseña hasheada
username parcial1 secret cisco123

! Configuración del modo EXEC privilegiado
enable secret cisco

! Configuración de las llaves crypto
crypto key generate rsa 
  ! Cuando pregunte si desea reemplazar las llaves, responde "yes"

! Configuración de la versión 2 de SSH
ip ssh version 2

! Configuración de las líneas vty 0 a 15 para que solo usen SSH
line vty 0 15
transport input ssh
login local
exec-timeout 0 0      
logging synchronous   
end
wr

============================
! ACC-SW2

enable
configure terminal

hostname ACC-SW2
ip domain-name up.edu.mx

! Configuración de la interfaz VLAN 10
interface vlan 10
ip address 192.168.10.23 255.255.255.0
no shutdown

! Configuración del Default Gateway
ip default-gateway 192.168.10.1

! Creación del usuario con contraseña hasheada
username parcial1 secret cisco123

! Configuración del modo EXEC privilegiado
enable secret cisco

! Configuración de las llaves crypto
crypto key generate rsa 
  ! Cuando pregunte si desea reemplazar las llaves, responde "yes"

! Configuración de la versión 2 de SSH
ip ssh version 2

! Configuración de las líneas vty 0 a 15 para que solo usen SSH
line vty 0 15
transport input ssh
login local
exec-timeout 0 0      
logging synchronous   
end
wr

=== conf consola


! Configuración de la línea de consola
conf t
line console 0
login local
logging synchronous
exit

! Guardar configuración
end
write memory





======================================================================
! PARTE 3

enable
configure terminal

! Creación de VLAN 10 para el área de IT
vlan 10
name IT
exit

! Creación de VLAN 20 para el área de Students
vlan 20
name Students
exit

! Creación de VLAN 30 para el área de Teachers
vlan 30
name Teachers
exit

! Guardar configuración
end
write


=============
! CONFIGURACION SWITCH DE ACCESO
configure terminal

! Asignar las VLANs correspondientes a las interfaces que conectan con las computadoras
interface fa 0/1
switchport mode access
switchport access vlan 10
switchport nonegotiate   
exit

interface fa 0/2
switchport mode access
switchport access vlan 20
switchport nonegotiate   
exit

interface fa 0/3
switchport mode access
switchport access vlan 30
switchport nonegotiate   
exit

! Configuración de la interfaz troncal en los switches de acceso
interface range gi 0/1, gi 0/2
switchport mode dynamic auto    
switchport trunk native vlan 10 
exit

end
write

=============
! CONFIGURACION SWITCH DE DISTRIBUCIÓN

configure terminal

! Configuración de la interfaz troncal en los switches de distribución
interface range gi 1/0/1, gi 1/0/2
! switchport trunk encapsulation dot1q
switchport mode dynamic desirable
switchport trunk native vlan 10
exit

end
write


======================================================================
! PARTE 4

! todos los switches
configure terminal
spanning-tree mode rapid-pvst
exit


! dist-sw1
configure terminal

! Establecer prioridad para VLAN 10
spanning-tree vlan 10 priority 4096

! Prioridad VLAN 20
spanning-tree vlan 20 priority 8192

! Asegurarse de que DIST-SW1 sea el primario para VLAN 30 (Teachers)
spanning-tree vlan 30 root primary
exit


! dist-sw2
configure terminal

! Establecer prioridad para VLAN 20
spanning-tree vlan 20 priority 4096

! Establecer prioridad de respaldo para VLAN 10 y VLAN 30
spanning-tree vlan 10 priority 8192
spanning-tree vlan 30 root secondary
exit


! costo preferido en el enlace ACC-SW2 a DIST-SW1:
configure terminal

! Configurar el costo en la interfaz GigabitEthernet0/2 hacia DIST-SW1
interface GigabitEthernet0/2
spanning-tree cost 3
exit


===========================================================
PARTE 5

configure terminal

! Configurar las interfaces físicas para EtherChannel
interface range gi 1/1/3, gi 1/1/4
channel-group 1 mode on
no shutdown
exit

! Ingresar a la interfaz lógica del EtherChannel
interface Port-channel 1
switchport mode trunk
switchport trunk native vlan 10
exit



