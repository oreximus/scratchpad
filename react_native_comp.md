## React Native Components:

**source**: https://www.youtube.com/watch?v=-d3ti_YW-OM

### View

- King of all react native component, maps directly to the native view, on whatever platform you are using. You can
  use it directly or you can build custom build on top of it. - This is the Div of the react native.

### Text

- Also a foundational component, you can use it directly `<Text>Some text</Text>` or:

```
const MyText = () => {
    return <Text style={{color: blue}}>{value}</Text>
}
```

### TextInput

- Is used to how user input the text into your app, It comes with lot of properties like: `autocorrection`, `placeholder`,
  etc.

```
<TextInput
 autoCorrect={true}
 placeholder="type here"
 value={this.state.value}
/>
```

### ScrollView

- It's used to load the long content that's longer than the screen, and you just need the scrolling functionality there,
  but it's also not that optimized by default, so if you have very large content, then you can probably run into some
  performance issues.

### FlatList

- For solving performance related problem in scrolling content, the FlatList comes into the play. And it's very
  customizable, you can pass the data to load in the scrolling area, and also can define how the data should be represented.

```
<FlatList
 data={[]}
/>
```

- If you need another way to load the data you have, then you can use the prop called `extraData`

> FlatList is good for most of the time when you need to the load the data in the very optimized way, but if really
> need to optimize more of the performance then take a look at `RecyclerListView` by Flipkart.

### SectionList

- very similar to FlatList but then your list of data is organized into your sections, and each of sections can have
  a `section` header. For example, like if you have a list of contacts that you need to display using the `SectionList`,
  then you contacts will get separated like in Alphabetical Order.

### ActivityIndicator

- It's an activity indication animation.

### Image

- It's used to shown an image.

### ImageBackground

- It's a basic way to show a whole background image.

### KeyboardAvoidingView

- KeyboardAvoidingView, helps us to manage the view while opening the keyboard to input some data, but this does not
  works with List and in IOS, you need to manage there by manual approach.

### Modal

- It's a very basic component, for building modal.

### RefreshControl

- Used inside the ScrollView or List, so you can refresh the content.

### SafeAreaView

- SafeAreaView adds the extra padding around your screen, for example in IOS, the padding around the camera notch.

### StatusBar

- Controls the status bar in your app.

### Switch

- Just our basic boolean switch component

### TouchableHighlight

- for handling touchs, TouchableHighlight allows us to handle use to touches, when it get touches, it's shows like
  the hovering effect same as hovering cursor effect on buttons in the website.

### TouchableOpacity

- also used for handling touches, and it dims out the opacity when we touch it.

### TouchableWithoutFeedback

- on touching this will not change the opacity or dimmed out in any manner, so make you use it by applying some feedback
  functionality to it.

### Pressable

- It's one of the newest component from the react native, you can use it over above three touchable components.

### Button

- Simple button component.

### VirtualizedList

- It's the base component for the FlatList and SectionList.

### DrawlerLayoutAndroid

- Pops a little menu from either left side or right side of the screen.

### TouchNativeFeedback

- It contains the rippler effect.

### InputAccessaryView (IOS only component)

- It puts a view up on the top of the keyboard.
