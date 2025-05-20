export interface Contacto {
  id: string;
  nombre: string;
  telefono: string;
  correo: string;
}


export const ejemplos: Contacto[] = [
  { id: '1', nombre: 'Juan P', telefono: '123456789', correo: 'juan@perez.com' },
  { id: '2', nombre: 'Ana Lopez', telefono: '987654321', correo: 'ana@lopex.com' },
];
