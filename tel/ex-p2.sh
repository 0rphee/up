

!!!!!!!!!!!!!!!!! SWITCHING !!!!!!!!!!!!!!!!!


!!!!! INCISO 1. !!!!!
!!! AVANCE 8% (+8%)

! VLAN 100 – Ingeniería
! VLAN 200 – Finanzas

! SW 3650 (Sw_Vancouver_1) root bridge de STP para la VLAN 100 y el equipo Sw_Vancouver_3 debería ser el root bridge para la VLAN 200

!!! Sw_Vancouver_1 (switch grande)

conf t
spanning-tree vlan 100 priority 0
end
wr

!!! Sw_Vancouver_3

conf t
spanning-tree vlan 200 priority 0
end
wr

!!!!! INCISO 2. !!!!!
!!! AVANCE 16% (+8%)

! 2.- Por otro lado, dentro de los mismos comentarios que nos hicieron, nos han dicho que Sw_Vancouver_2 debe ser el respaldo para ambas VLANs como root bridge, es decir, si alguno de los otros switches falla, Sw_Vancouver_2 debe quedar como root en STP para ambas VLAN con el siguiente valor disponible de prioridad.

! Sw_Vancouver_2 respaldo para ambas VLANs como root bridge, con el siguiente valor disponible de prioridad


!!! Sw_Vancouver_2

conf t
spanning-tree vlan 100 priority 4096
spanning-tree vlan 200 priority 4096
end
wr


!!!!! INCISO 3. !!!!!
!!! AVANCE 20 (+4%)

! 3.- Una vez que se hayan logrado esos puntos, les pediré su ayuda también para confirmar que Sw_Vancouver_1 nunca se vuelva root de VLAN 200.

!!! Sw_Vancouver_1

conf t
spanning-tree vlan 200 priority 61440
end
wr


!!!!! INCISO 4. !!!!!
!!! AVANCE 24% (+4%)

! 4.- Otro problema que hemos enfrentado es con el director de ingeniería de la oficina de Vancouver. Sucede que los directores utilizan Laptop y el director alega que su computadora tarda demasiado en entrar a la red cuando conecta el cable de su oficina. Nos comentaron por teléfono que se pueden hacer movimientos en la configuración para cambiar este tiempo de conexión y ser más rápida ¿cierto?

! Acelerar conexión laptop ingeniería vancouver

!!! Sw_Vancouver_1

conf t
int gi 1/0/4
spanning-tree portfast
end
wr

!!!!! INCISO 5. !!!!!
!!! AVANCE 28% (+4%)

! 5.- Por último, en el tema de switching, en Monterrey tenemos un servidor de producción que desde hace 3 días no es alcanzable por el equipo de ingeniería. El viernes pasado, se realizó una ventana de mantenimiento por parte de un proveedor en el switch Sw_Monterrey_1 pero erróneamente se confirmó que todo estaba bien y ahora los equipos de ingeniería no pueden entrar al server. Esto es urgente ya que parte de sus pruebas las corren desde ahí ¿nos ayudan a obtener acceso nuevamente? Es importante mencionarles que las VLANs que están configuradas y permitidas en el switch deben permanecer configuradas.

!!! Sw_Monterrey_1

conf t
int gi 0/1
switchport trunk allowed vlan 10-20,35,102,100
end
wr

!!!!!!!!!!!!!!!!! ROUTING !!!!!!!!!!!!!!!!!

!!!!! INCISO 6. !!!!!
!!! AVANCE 38% (+10%)

! 6.- Nuestra red estaba basada en OSPF y tenemos conexiones entre nuestras oficinas utilizando este protocolo. En nuestra topología, la oficina de Vancouver tiene 2 enlaces para redundancia, sin embargo, por cuestión de diseño, siempre hemos preferido que el enlace que tiene conexión a Edmonton tenga prioridad sobre el enlace que va a NY para llegar a Toronto. La semana pasada nos avisaron que el enlace que se está utilizando para llegar a Toronto es el de NY pero no sabemos qué pasó con Edmonton ¿nos pueden ayudar a verificar y componer la conexión entre Vancouver y Edmonton? Algunos equipos tienen configuración con el comando “network” y otros tantos con el comando “ip ospf” les pido no cambiar esto.

! reestablecer conexión Vancouver - Edmonton, manteniendo comandos network y ip ospf iguales

!!! Vancouver

!!! Edmonton

! 33% (+5%), levanta la conexión 
conf t
int gi 0/0/0
no shutdown
end
wr

! 63% (+12%)
conf t
router ospf 10
network 192.168.100.12 0.0.0.3 area 0
end
wr

!!! Toronto

! 38% (+5%), levanta la conexión 
conf t
int gi 0/0
no shutdown
end
wr


!!!!! INCISO 7. !!!!!
!!! AVANCE 51% (+13%)

! 7.- En cuanto a OSPF como tal, hemos visto que en nuestra red punto a punto entre Edmonton y Toronto, aparece un DR y BDR cuando en nuestros demás enlaces no aparece. Aquí es importante mencionar que por una situación con nuestro ISP la conexión entre Toronto, CDMX y Monterrey es una red multiacceso, no así, en EEUU y Canadá donde cada conexión es punto a punto. Requerimos su ayuda para saber por qué aparecen un DR y BDR en la conexión entre Edmonton y Toronto y eliminar esto para que aparezca como en las demás conexiones de EEUU y Canadá. Al momento, tenemos la interfaz G0/0 de Toronto apagada ya que, cuando se enciende, se pierden las conexiones de OSPF. Por favor, tengan cuidado.

!!! Edmonton

conf t
int gi 0/1
ip ospf network point-to-point
end
wr

!!! Toronto

conf t
int gi 0/0
ip ospf network point-to-point
end
wr

!!!!! INCISO 8. !!!!!
!!! AVANCE 

! 8.- Como parte de lo solicitado por el proveedor externo que nos ayudó con el diseño, queremos pedirles que podamos confirmar que, dentro de nuestra red multiacceso (CDMX, Mty y Toronto) podamos hacer que CDMX sea el DR y Monterrey el BDR. Les pido no manipulen el Router ID de nuestros equipos, busquen otra manera de lograrlo. Siempre usamos el 10 como valor de referencia en cuanto el DR respecta.

! CDMX DR
! Monterrey BDR
! Sin manipular Router ID's
! 10, valor de referencia para el DR


!!! Mexico City
! AVANCE 75% (+12%)

conf t
int gi 0/0
ip ospf priority 10
end
wr

conf t
int gi 0/0/0
ip ospf priority 10
end
wr

!!! Monterrey
! AVANCE 75% (+12%)

conf t
int gi 0/0
ip ospf priority 9
end
wr


! finalmente hacer
clear ip ospf process

!!!!! INCISO 9. !!!!!
!!! AVANCE 


!!!!! INCISO 10. !!!!!
!!! AVANCE 



