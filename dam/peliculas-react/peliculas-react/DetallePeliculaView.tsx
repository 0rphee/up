// DetallePeliculaView.tsx
import React from 'react';
import { View, Text, Button, StyleSheet } from 'react-native';
import { useRoute, useNavigation } from '@react-navigation/native';
import { Pelicula } from './DataModel'; // Import the Pelicula interface

type RouteParams = {
  pelicula: Pelicula;
  onEditar: (pelicula: Pelicula) => void;
};

const DetallePeliculaView: React.FC = () => {
  const route = useRoute();
  const navigation = useNavigation();
  const { pelicula, onEditar } = route.params as RouteParams;

  return (
    <View style={styles.container}>
      <Text style={styles.title}>{pelicula.titulo}</Text>
      <Text>Director: {pelicula.director}</Text>
      <Text>Año: {pelicula.anio}</Text>
      <Text>Reseña: {pelicula.resena}</Text>
      <Text>Calificación: {pelicula.calificacion}/5</Text>
      <Text style={{ color: pelicula.vista ? 'green' : 'red', fontWeight: 'bold' }}>
        {pelicula.vista ? 'VISTA' : 'NO VISTA'}
      </Text>
      <Button title="Editar" onPress={() => onEditar(pelicula)} />
      <Button title="Volver" onPress={() => navigation.goBack()} />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    padding: 16,
  },
  title: {
    fontSize: 24,
    fontWeight: 'bold',
    marginBottom: 12,
  },
});

export default DetallePeliculaView;