import 'react-native-get-random-values';
import React, { useState, useEffect } from 'react';
import { View, Text, FlatList, Button, StyleSheet, TouchableOpacity } from 'react-native';
import { useNavigation } from '@react-navigation/native';
import { Picker } from '@react-native-picker/picker';
import { Swipeable } from 'react-native-gesture-handler';
import { ejemplos, Pelicula } from './DataModel.ts'; // Import Pelicula and ejemplos

 const ContentView: React.FC = () => {
  const [peliculas, setPeliculas] = useState<Pelicula[]>(ejemplos);
  const [filtro, setFiltro] = useState<string>('Todas');
  const navigation = useNavigation();

  const peliculasFiltradas = (): Pelicula[] => {
    switch (filtro) {
      case 'Vistas':
        return peliculas.filter((p) => p.vista);
      case 'No vistas':
        return peliculas.filter((p) => !p.vista);
      default:
        return peliculas;
    }
  };

  const handleGuardarPelicula = (nuevaPelicula: Pelicula) => {
    const index = peliculas.findIndex((p) => p.id === nuevaPelicula.id);
    if (index !== -1) {
      const updatedPeliculas = [...peliculas];
      updatedPeliculas[index] = nuevaPelicula;
      setPeliculas(updatedPeliculas);
    } else {
      setPeliculas([...peliculas, nuevaPelicula]);
    }
  };

  const renderPeliculaItem = ({ item }: { item: Pelicula }) => (
    <Swipeable
      renderRightActions={() => (
        <TouchableOpacity
          style={styles.deleteButton}
          onPress={() => handleDeletePelicula(item.id)}
        >
          <Text style={styles.deleteButtonText}>Eliminar</Text>
        </TouchableOpacity>
      )}
      renderLeftActions={() => (
        <TouchableOpacity
          style={styles.vistaButton}
          onPress={() => handleToggleVista(item.id)}
        >
          <Text style={styles.vistaButtonText}>
            {item.vista ? 'No Vista' : 'Vista'}
          </Text>
        </TouchableOpacity>
      )}
    >
      <TouchableOpacity
        style={styles.peliculaItem}
        onPress={() =>
          navigation.navigate('DetallePelicula', {
            pelicula: item,
            onEditar: (pelicula: Pelicula) =>
              navigation.navigate('FormularioPelicula', {
                pelicula,
                onGuardar: handleGuardarPelicula,
              }),
          })
        }
      >
        <Text>{item.titulo}</Text>
      </TouchableOpacity>
    </Swipeable>
  );

  const handleDeletePelicula = (id: string) => {
    setPeliculas(peliculas.filter((p) => p.id !== id));
  };

  const handleToggleVista = (id: string) => {
    const updatedPeliculas = peliculas.map((p) =>
      p.id === id ? { ...p, vista: !p.vista } : p
    );
    setPeliculas(updatedPeliculas);
  };

  return (
    <View style={styles.container}>

      <Picker
        selectedValue={filtro}
        onValueChange={(itemValue) => setFiltro(itemValue)}
        style={styles.picker}
      >
        <Picker.Item label="Todas" value="Todas" />
        <Picker.Item label="Vistas" value="Vistas" />
        <Picker.Item label="No vistas" value="No vistas" />
      </Picker>

      <FlatList
        data={peliculasFiltradas()}
        renderItem={renderPeliculaItem}
        keyExtractor={(item) => item.id}
      />

      <Button
        title="Agregar"
        onPress={() =>
          navigation.navigate('FormularioPelicula', {
            onGuardar: handleGuardarPelicula,
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
  picker: {
    height: 200,
    width: '100%',
    marginBottom: 16,
  },
  peliculaItem: {
    paddingVertical: 12,
    borderBottomWidth: 1,
    borderBottomColor: '#ccc',
  },
  deleteButton: {
    backgroundColor: 'red',
    justifyContent: 'center',
    paddingHorizontal: 16,
  },
  deleteButtonText: {
    color: 'white',
  },
  vistaButton: {
    backgroundColor: 'blue',
    justifyContent: 'center',
    paddingHorizontal: 16,
  },
  vistaButtonText: {
    color: 'white',
  },
});

export default ContentView;