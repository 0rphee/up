// DataModel.ts
import 'react-native-get-random-values';
import { v4 as uuidv4 } from 'uuid'; // For generating IDs

interface Pelicula {
  id: string;
  titulo: string;
  director: string;
  anio: number;
  resena: string;
  calificacion: number;
  vista: boolean;
}

class PeliculaClass implements Pelicula {
  id: string;
  titulo: string;
  director: string;
  anio: number;
  resena: string;
  calificacion: number;
  vista: boolean;

  constructor(
    titulo: string,
    director: string,
    anio: number,
    resena: string,
    calificacion: number,
    vista: boolean,
    id: string = uuidv4()
  ) {
    this.id = id;
    this.titulo = titulo;
    this.director = director;
    this.anio = anio;
    this.resena = resena;
    this.calificacion = calificacion;
    this.vista = vista;
  }
}

const interestellar: Pelicula = new PeliculaClass(
  "Interstellar",
  "Christopher Nolan",
  2014,
  "Viaje a estrellas",
  5,
  true,
  uuidv4()
);

const orgullo: Pelicula = new PeliculaClass(
  "Orgullo y Prejuicio",
  "Joe Wright",
  2005,
  "Adaptación",
  4,
  true,
  uuidv4()
);

const dune: Pelicula = new PeliculaClass(
  "Dune",
  "Denis Villeneuve",
  2020,
  "Dune",
  4,
  false,
  uuidv4()
);

const ejemplos: Pelicula[] = [interestellar, orgullo, dune];

export { Pelicula, PeliculaClass, ejemplos };