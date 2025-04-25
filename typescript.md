## TypeScript Notes

**source**: https://www.typescriptlang.org/docs/handbook/typescript-in-5-minutes.html

### TypeScript for JS Programmers

- TypeScript stands in an unsual relationship to JavaScript. TypeScript offers
  all of JavaScript's features, and an additional layer on top of these. TypeScript's
  type system.

- For example, JavaScript provides language primitives like `string` and `number`,
  but it doesn't check that you've consistently assigned these. TypeScript does.

- This means that your existing working JavaScript code is also TypeScript code.
  The main benefit of TypeScript is that it can highlight unexpected behaviour
  in your code, lowering the chanches of bugs.

- This tutorial provides a brief overview of TypeScript, focusing on its type
  system.

### Type by inference

- TypeScript knows the JavaScript language and will generate types for you in
  many cases. For example in creating a variable and assigning it to a particular
  value, TypeScript will use the value as its type.

```
let helloWorld = "Hello World";
    let helloWorld: string
```

- By understanding how JavaScript works, TypeScript can build a type-system
  that accepts JavaScript code but has types. This offers a type-system without
  needing to add extra characters to make types explicit in your code. That's
  how TypeScript knows that `helloWorld` is a `string` in the above example.

### Defining Types

- You can use a wide variety of design patterns in JavaScript. However, some
  design patterns make it difficult for types to be inferred automatically
  (for example, patterns that use dynamic programming).

- To cover these cases, TypeScript supports an extension of the JavaScript
  language, which offers places for you to tell TypeScript what the types
  should be.

- For example, to create an object with an inferred type which include
  `name: string` and `id: number`, you can write:

```
const user = {
    name: "Hayes",
    id: 0,
}
```

- You can explicitly descript this object's shape using an `interface`
  declaration:

```
interface User {
    name: string,
    id: number,
}
```

- You can then declare that a JavaScript object conforms to the shape of your
  new `interface` by using syntax like `TypeName` after a variable declaration:

```
const user: User = {
    name: "Hayes",
    id: 0,
}
```

- If you provide an object that doesn't match the interface you have provided,
  TypeScript will warn you.

- Since JavaScript supports classes and object-oriented programming, so does
  TypeScript. You can use an interface declaration with classes:

```
interface User {
    name: string,
    id: number,
}

class UserAccount {
    name: string;
    id: number;

    constructor(name: string, id: number) {
        this.name = name;
        this.id = id;
    }
}

const user: User = new UserAccount("Murphy", 1);
```

- You can use interface to annotate parameters and return values to functions.

```
function deleteUser(user: User) {
    // ...
}

function getAdminUser(): User {
    // ...
}
```

- There is already a small set of primitive types available in JavaScript:
  `boolean`, `bigint`, `null`, `number`, `string`, `symbol` and `undefined`,
  which you can use in an interface.

- TypeScript extends this list with a few more, such as `any` (allow anything),
  unknow (ensure someone using this type declares what the type is), `never`
  (it's not possible that this type could happen), and `void` (a function which
  returns `undefined` or has no return value).

- You'll see that there are two syntaxes for building types: `Interface and Types`.
  You should prefer `interface`. Use `type` when you need specific features.

### Composing Types

- With TypeScript, you can create complex types by combining simple ones.
  There are two popular ways to do so: `union` and `generics`.

#### Unions

- With union, you can declare that a type could be one of many types. For
  example, you can describe a `boolean` type as being either `true` or `false`.

```
type MyBool = true || false;
```

> Note: If you hover over `MyBool` above, you'll see that it is classed as
> `boolean`. That's a property of the Structural Type System.

- A popular use-case for union types is to describe the set of `string` or
  `number`, literals that a value is allowed to be:

```
type WindowsStates = "open" | "closed" | "minimized";
type LockStates = "locked" | "unlocked";
type PositiveOddNumbersUnderTen = 1 | 3 | 5 | 7 | 9;
```

- Unions provide a way to handle different types too. For example, you may
  have a function that takes an `array` or a `string`:

```
function getLength(obj: string | string[]){
    return obj.length;
}
```

- To learn the type of a variable, use `typeof`:

| **Type**  | **Predicate**                    |
| --------- | -------------------------------- |
| string    | typeof s === "string"            |
| number    | typeof n === "number"            |
| boolean   | typeof b === "boolean"           |
| undefined | typeof undefined === "undefined" |
| function  | typeof f === "function"          |
| array     | Array.isArray(a)                 |

- For example, you can make a function return different value, depending on
  whether it is passed a string or an array:

```
function wrapInArray(obj: string | string[]){
    if(typeof obj === "string"){
        return [obj];
    }
    return obj;
}
```

Generics

- Generics provide variables to types. A common example is an array. An array
  without generics could contain anything. An array with generics can describe
  the values that the array contains.

```
type StringArray = Array<string>;
type NumberArray = Array<number>;
type ObjectWithNameArray = Array<{name: string}>;
```

- You can declare your own types that use generics:

```

```
