import React from 'react';
import { View, Text, Button, StyleSheet } from 'react-native';
import { useRoute, useNavigation } from '@react-navigation/native';
import { Contacto } from './DataModel';

type RouteParams = {
  contacto: Contacto;
  onEditar: (contacto: Contacto) => void;
};

const Detalle: React.FC = () => {
  const route = useRoute();
  const navigation = useNavigation();
  const { contacto, onEditar } = route.params as RouteParams;

  return (
    <View style={styles.container}>
      <Text style={styles.title}>{contacto.nombre}</Text>
      <Text>Teléfono: {contacto.telefono}</Text>
      <Text>Correo: {contacto.correo}</Text>
      <Button title="Editar" onPress={() => onEditar(contacto)} />
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

export default Detalle;
