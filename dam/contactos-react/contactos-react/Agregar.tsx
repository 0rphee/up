import React, { useState } from 'react';
import { View, TextInput, Button, StyleSheet } from 'react-native';
import { useNavigation, useRoute } from '@react-navigation/native';
import { Contacto } from './DataModel';

const Agregar: React.FC = () => {
  const route = useRoute();
  const navigation = useNavigation();

  const contacto = route.params?.contacto;
  const onGuardar = route.params?.onGuardar;

  const [nombre, setNombre] = useState(contacto?.nombre ?? '');
  const [telefono, setTelefono] = useState(contacto?.telefono ?? '');
  const [correo, setCorreo] = useState(contacto?.correo ?? '');

  const handleGuardar = () => {
    if (!onGuardar) return; // Seguridad por si no llega onGuardar

    const nuevoContacto: Contacto = {
      id: contacto?.id ?? Date.now().toString(),
      nombre,
      telefono,
      correo,
    };

    onGuardar(nuevoContacto);
    navigation.goBack();
  };

  return (
    <View style={styles.container}>
      <TextInput
        placeholder="Nombre"
        value={nombre}
        onChangeText={setNombre}
        style={styles.input}
      />
      <TextInput
        placeholder="Teléfono"
        value={telefono}
        onChangeText={setTelefono}
        keyboardType="phone-pad"
        style={styles.input}
      />
      <TextInput
        placeholder="Correo"
        value={correo}
        onChangeText={setCorreo}
        keyboardType="email-address"
        style={styles.input}
      />
      <Button title="Guardar" onPress={handleGuardar} />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    padding: 16,
  },
  input: {
    borderWidth: 1,
    borderColor: '#ccc',
    marginBottom: 12,
    padding: 8,
    borderRadius: 4,
  },
});

export default Agregar;
