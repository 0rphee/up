import { StatusBar } from 'expo-status-bar';
import React, { useState } from "react";
import { Button, SafeAreaView, StyleSheet, Text, View as View } from 'react-native';


export default function App() {
  const [count, setCount] = useState<number>(0);

  return (

    <SafeAreaView style={styles.safe}>
      <View style={styles.container}>
        <Text style={styles.title}>Has pulsado:</Text>
        <Text style={styles.count}>{count} veces:</Text>

        <View style={styles.buttons}>
          <Button title="Pulsa aquí" onPress={() => setCount(count + 1)} />

          <Button title="Reiniciar" onPress={() => setCount(0)} />
        </View>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  safe: { flex: 1, backgroundColor: "#f0f0f0" },

  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },

  text: {
    fontSize: 20,
    fontWeight: "bold",
    color: "black",
    alignContent: "center",
    justifyContent: "center",
    textAlign: "center",
  },
  title: {
    fontSize: 20,
    marginBottom: 10,
  },

  count: {
    fontSize: 23,
    fontWeight: "bold",
    marginBottom: 20,
  },

  buttons: {
    flexDirection: "row",
    justifyContent: "center",
    width: "100%",
    gap: 30,
  }

});
