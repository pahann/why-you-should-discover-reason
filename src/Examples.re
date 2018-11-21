let deck = {js|return (
    <Deck transition={['zoom','slide']} transitionDuration={800}>
      <Slide bgColor="primary">
        <Heading size={1} fit caps>
          React Presentations
        </Heading>
        <Heading size={2} fit caps>
          Written In React
        </Heading>
      </Slide>
      <Slide bgColor="black">
        <Heading size={1} fit textColor="primary" textFont="secondary">
          Wait What?
        </Heading>
      </Slide>
      <Slide bgColor="primary" textColor="black" align="center top">
        <Heading size={1} textColor="black" textFont="primary">
          Thats right
        </Heading>
        <List>
          <ListItem>Inline style based theme system</ListItem>
          <ListItem>Autofit Text</ListItem>
          <ListItem>PDF Export</ListItem>
        </List>
      </Slide>
    </Deck>
  )
  |js};

  let reduxProblemActions = {js|
const addPost = ({title, body}) => ({
    actionType: "ADD_POST",
    payload: { id: makeMeUnique(),
               title,
               body,
    },
})
const bodyAction = id => ({
    actionType: "DEL_POST",
    payload: id,
})
|js};

let reduxProblemReducer = {js|
const reducer = (state = [], action) => switch (action.actionType) {
  case "DEL_POSTS":
      return state.filter(
          ({id}) => id !== action.payload
      )
  case "ADD_POST":
      return [...state, action.payload]
  default:
      return state
}
|js};

let reduxProblemReducerThrow = {js|
export default (state = [], action) => switch (action.type) {
  case "DEL_POSTS":
      return state.filter(
          ({id}) => id !== action.payload
      )
  case "ADD_POST":
      return [...state, action.payload]
  default:
      throw("What's wrong bro ?! Should not happen in prod")
}
|js};


let candyFunc = {js|
function candyFunction(beautifulObject) {
  beautifulObject.id = 42
  return false
}
|js};


let reason = {js|
  let welcome = (name) => {
    "Hello " ++ name
  };

  Js.log(welcome("NodeJS Paris !"));
|js};


let welcomers = {js|
  let welcome = (~welcomeMessage="Welcome", name) => {
    welcomeMessage ++ name
  };

  let hello = welcome(~welcomeMessage="Hello ")

  Js.log(welcome("NodeJS Paris !"));
  Js.log(hello("NodeJS Paris !"));
|js};


let records = {js|
  type person = {
    age: int,
    name: string
  };

  let me = {
    age: 35,
    name: "Bob"
  };

  Js.log(me.name);
|js};


let variants = {js|
  type pets = Cat | Fish | Dog(string);
|js};

let patmat = {js|
  type schoolPerson = Teacher | Director | Student(string);

  let greeting = person =>
    switch (person) {
    | Teacher => "Hey Professor!"
    | Director => "Hello Director."
    | Student("Etienne") => "Still here Etienne?"
    | Student(anyOtherName) => "Hey, " ++ anyOtherName ++ "."
    };

  Js.log(greeting(Teacher));
  Js.log(greeting(Student("Etienne")));
  Js.log(greeting(Student("Quentin")));
|js};


let reReduxProblemActions = {js|
type post = {
  id: int,
  title: string,
  body: string,
};
type actionType = AddPost(post) | DelPost(int)

let addPost = (~title, ~body) => AddPost({
  id: makeMeUnique(),
  title,
  body,
});

let delPost = (id) => DelPost(id);
|js};

let reReduxProblemReducer = {js|
let reducer = (~state=[], ~action) => switch (action) {
  | AddPost(post) => [post, ...state]
  | DelPosts(delId) => List.filter(
    ({id}) => id !== delId,
    state,
  )
};
|js};



let reReduxProblemActionsExhaustive = {js|
type post = {
  id: int,
  title: string,
  body: string,
};
type actionType = AddPost(post) | DelPost(int) | DelByTitle(string)

let addPost = (~title, ~body) => AddPost({
  id: makeMeUnique(),
  title,
  body,
});

let delPost = (id) => DelPost(id)
|js};

let reReduxProblemReducerFixed = {js|
let reducer = (~state=[], ~action) => switch (action) {
  | AddPost(post) => [post, ...state]
  | DelPost(delId) => List.filter(
    ({id}) => id !== delId,
    state,
  )
};
|js};


let bucklescript = {js|
[@bs.val] external setTimeout : (unit => unit, int) => float = "setTimeout";
|js};


let bucklescriptraw = {js|
let add = [%raw "a + b"];
[%%raw "var a = 1"];
let myFunction = [%raw (a, b) => "return a + b"];
|js};



let reasonreact = {js|
let component = ReasonReact.statelessComponent("Greeting");

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <button>
      {ReasonReact.string("Hello!")}
    </button>
};
|js};
