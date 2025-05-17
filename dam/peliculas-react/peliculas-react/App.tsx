import 'react-native-gesture-handler'; //  Important for react-navigation/stack
import 'react-native-get-random-values';
import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import ContentView from './ContentView';
import FormularioPeliculaView from './FormularioPeliculaView';
import DetallePeliculaView from './DetallePeliculaView';
 
const Stack = createStackNavigator();

export default function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName='ContentView'>
        <Stack.Screen name="ContentView" component={ContentView} options={{ title: 'Películas' }} />
        <Stack.Screen name="FormularioPelicula" component={FormularioPeliculaView} options={{ title: 'Nueva Película' }} />
        <Stack.Screen name="DetallePelicula" component={DetallePeliculaView} options={{ title: 'Detalle' }} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}