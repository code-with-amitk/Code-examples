// Add StyleSheet to create a styles object to define our custom styles
import { Text, View, StyleSheet } from "react-native";

export default function Index() {
  return (
    <View style={styles.container}>
      <Text style={styles.text}>Amit's 1st App</Text>
    </View>
  );
}

/* https://reactnative.dev/docs/stylesheet
Stylesheets in React-Native
StyleSheet is an abstraction similar to CSS StyleSheets.
*/
const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#25292e',
    alignItems: 'center',
    justifyContent: 'center',
  },
  text: {
    color: '#fff',
  },
});
