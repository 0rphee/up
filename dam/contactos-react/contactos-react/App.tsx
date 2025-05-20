import 'react-native-gesture-handler';

import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import Contactos from './Contactos';
import Agregar from './Agregar';
import Detalle from './Agregar';

const Stack = createStackNavigator();

export default function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName='Contactos'>
        <Stack.Screen name="Contactos" component={Contactos} />
        <Stack.Screen name="Agregar" component={Agregar} />
        <Stack.Screen name="Detalle" component={Detalle} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}
