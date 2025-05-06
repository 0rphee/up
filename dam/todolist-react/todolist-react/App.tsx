import { StatusBar } from "expo-status-bar";
import { useState } from "react";
import {
  StyleSheet,
  Text,
  View,
  TouchableOpacity,
  Button,
  SafeAreaView,
  TextInput,
  FlatList,
} from "react-native";

interface Task {
  id: string;
  title: string;
  done: boolean;
}

export default function App() {
  const [tasks, setTask] = useState<Task[]>([]);
  const [input, setInput] = useState<string>("");

  const addTask = () => {
    if (!input.trim()) return;
    const newTask: Task = {
      id: Date.now().toString(),
      title: input.trim(),
      done: false,
    };
    setTask((prev) => [newTask, ...prev]);
    setInput("");
  };

  const toggleDone = (id: string) => {
    setTask((prev) =>
      prev.map((t) => (t.id === id ? { ...t, done: !t.done } : t))
    );
  };

  const deleteTask = (id: string) => {
    setTask((prev) => prev.filter((t) => t.id !== id));
  };

  const renderItem = ({ item }: { item: Task }) => (
    <View style={styles.tastkItem}>
      <TouchableOpacity onPress={() => toggleDone(item.id)}>
        <Text style={[styles.taskText, item.done && styles.done]}>
          {item.done ? `✅ ${item.title}` : item.title}
        </Text>
      </TouchableOpacity>
      <Button title="🗑️" onPress={() => deleteTask(item.id)} />
    </View>
  );

  return (
    <SafeAreaView style={styles.safe}>
      <Text style={styles.header}>Todo List</Text>
      <View style={styles.inputContainer}>
        <TextInput
          style={styles.input}
          value={input}
          onChangeText={setInput}
          placeholder="Nueva tarea"
        />
        <Button title="Agregar" onPress={addTask} />
      </View>
      {tasks.length === 0 ? (
        <Text style={styles.empty}>No hay tareas</Text>
      ) : (
        <FlatList
          data={tasks}
          renderItem={renderItem}
          keyExtractor={(item) => item.id}
        />
      )}
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  safe: { flex: 1, backgroundColor: "white", paddingHorizontal: 20 },
  header: {
    fontSize: 24,
    fontWeight: "bold",
    textAlign: "center",
    marginBottom: 20,
  },
  inputContainer: {
    flexDirection: "row",
    alignItems: "center",
    marginBottom: 20,
    gap: 10,
  },
  input: {
    flex: 1,
    borderWidth: 1,
    borderColor: "#ccc",
    borderRadius: 8,
    padding: 10,
    fontSize: 16,
  },
  empty: {
    fontSize: 18,
    color: "#888",
    textAlign: "center",
  },
  tastkItem: {
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "space-between",
    paddingVertical: 10,
    borderBottomWidth: 1,
    borderBottomColor: "#ccc",
  },
  taskText: {
    fontSize: 16,
  },
  done: {
    textDecorationLine: "line-through",
    color: "#999",
  },
});
