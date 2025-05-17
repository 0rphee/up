import { v4 as uuidv4 } from 'uuid'; // For generating IDs
import React, { useState, useEffect } from 'react';
import { View, Text, TextInput, Button, StyleSheet, ScrollView } from 'react-native';
import { useNavigation, useRoute } from '@react-navigation/native';
import { Pelicula } from './DataModel'; // Import the Pelicula interface

type RouteParams = {
  pelicula?: Pelicula;
  onGuardar: (pelicula: Pelicula) => void;
};

const FormularioPeliculaView: React.FC = () => {
  const route = useRoute();
  const navigation = useNavigation();

  const { pelicula: initialPelicula, onGuardar } = route.params as RouteParams;

  const [titulo, setTitulo] = useState<string>('');
  const [director, setDirector] = useState<string>('');
  const [anio, setAnio] = useState<string>('');
  const [resena, setResena] = useState<string>('');
  const [calificacion, setCalificacion] = useState<number>(3);
  const [vista, setVista] = useState<boolean>(false);

  useEffect(() => {
    if (initialPelicula) {
      setTitulo(initialPelicula.titulo);
      setDirector(initialPelicula.director);
      setAnio(String(initialPelicula.anio));
      setResena(initialPelicula.resena);
      setCalificacion(initialPelicula.calificacion);
      setVista(initialPelicula.vista);
    }
  }, [initialPelicula]);

  const handleGuardar = () => {
    if (!titulo || !director || !anio) {
      return; // Simple validation
    }
    const nuevaPelicula: Pelicula = {
      id: initialPelicula ? initialPelicula.id : uuidv4(),
      titulo,
      director,
      anio: parseInt(anio, 10),
      resena,
      calificacion,
      vista,
    };
    onGuardar(nuevaPelicula);
    navigation.goBack();
  };

  return (
    <ScrollView style={styles.container}>
      <Text style={styles.title}>
        {initialPelicula ? 'Editar Película' : 'Nueva Película'}
      </Text>
      <Text>Título</Text>
      <TextInput style={styles.input} value={titulo} onChangeText={setTitulo} />
      <Text>Director</Text>
      <TextInput style={styles.input} value={director} onChangeText={setDirector} />
      <Text>Año</Text>
      <TextInput style={styles.input} value={anio} onChangeText={setAnio} keyboardType="numeric" />
      <Text>Reseña</Text>
      <TextInput
        style={styles.input}
        multiline
        numberOfLines={4}
        value={resena}
        onChangeText={setResena}
      />
      <View style={styles.calificacionContainer}>
        <Text>Calificación: {calificacion}</Text>
        <View style={styles.stepperContainer}>
          <Button title="-" onPress={() => setCalificacion(Math.max(1, calificacion - 1))} />
          <Button title="+" onPress={() => setCalificacion(Math.min(5, calificacion + 1))} />
        </View>
      </View>
      <View style={styles.vistaContainer}>
        <Text>Vista</Text>
        <Button title={vista ? "Visto" : "No Visto"} onPress={() => setVista(!vista)} />
      </View>
      <Button title="Guardar" onPress={handleGuardar} />
      <Button title="Cancelar" onPress={() => navigation.goBack()} />
    </ScrollView>
  );
};

const styles = StyleSheet.create({
  container: {
    padding: 16,
  },
  title: {
    fontSize: 24,
    fontWeight: 'bold',
    marginBottom: 16,
  },
  input: {
    height: 40,
    borderColor: 'gray',
    borderWidth: 1,
    marginBottom: 12,
    paddingHorizontal: 8,
  },
  calificacionContainer: {
    flexDirection: 'row',
    alignItems: 'center',
    marginBottom: 12,
  },
  stepperContainer: {
    flexDirection: 'row',
  },
  vistaContainer: {
    flexDirection: 'row',
    alignItems: 'center',
    marginBottom: 12,
  },
});

export default FormularioPeliculaView;