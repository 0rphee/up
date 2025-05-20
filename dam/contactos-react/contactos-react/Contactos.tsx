import React, { useState } from 'react';
import { View, Text, FlatList, Button, StyleSheet, TouchableOpacity } from 'react-native';
import { useNavigation } from '@react-navigation/native';
import { Contacto, ejemplos } from './DataModel';

const Contactos: React.FC = () => {
  const [contactos, setContactos] = useState<Contacto[]>(ejemplos);
  const navigation = useNavigation();

  const handleGuardarContacto = (nuevoContacto: Contacto) => {
    const index = contactos.findIndex((c) => c.id === nuevoContacto.id);
    if (index !== -1) {
      const actualizados = [...contactos];
      actualizados[index] = nuevoContacto;
      setContactos(actualizados);
    } else {
      setContactos([...contactos, nuevoContacto]);
    }
  };

  const renderContactoItem = ({ item }: { item: Contacto }) => (
    <TouchableOpacity
      style={styles.contactoItem}
      onPress={() =>
        navigation.navigate('Detalle', {
          contacto: item,
          onEditar: (contacto: Contacto) =>
            navigation.navigate('Agregar', {
              contacto,
              onGuardar: handleGuardarContacto,
            }),
        })
      }
    >
      <Text>{item.nombre}</Text>
    </TouchableOpacity>
  );

  return (
    <View style={styles.container}>
      <FlatList
        data={contactos}
        renderItem={renderContactoItem}
        keyExtractor={(item) => item.id}
      />
      <Button
        title="Agregar"
        onPress={() =>
          navigation.navigate('Agregar', {
            onGuardar: handleGuardarContacto,
          })
        }
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 16,
  },
  contactoItem: {
    paddingVertical: 12,
    borderBottomWidth: 1,
    borderBottomColor: '#ccc',
  },
});

export default Contactos;
