open BsSpectacle;

let theme =
  Theme.(
    createTheme(
      {primary: "white", secondary: "black", tertiary: "#db4d3f", quarternary: "white"},
      {
        primary: {name: "Open Sans Condensed", googleFont: true, styles: [|"300", "700"|]},
        secondary: {name: "Lobster Two", googleFont: true, styles: [|"400", "700"|]},
        tertiary: simpleFont("monospace")
      }
    )
  );

type images = {
  city: string,
  me: string,
  markdown: string,
  reasonlogo: string,
  bucklescriptlogo: string,
  reactlogo: string,
  reasonocamljs: string,
  nuclear: string,
  questions: string,
  headdoor: string,
  headache: string,
  reasonconf: string,
  reasonconflogo: string,
};

let images: images = {
  city: [%raw {| require('./assets/city.jpg')|}],
  me: [%raw {| require('./assets/me.jpg')|}],
  reasonlogo: [%raw {| require('./assets/reason.svg')|}],
  reactlogo: [%raw {| require('./assets/reactlogo.svg')|}],
  bucklescriptlogo: [%raw {| require('./assets/bucklescriptlogo.svg')|}],
  reasonocamljs: [%raw {| require('./assets/reason-ocaml-js.jpg')|}],
  nuclear: [%raw {| require('./assets/nuclear.gif')|}],
  questions: [%raw {| require('./assets/questions.gif')|}],
  markdown: [%raw {| require('./assets/markdown.png')|}],
  headache: [%raw {| require('./assets/headache.gif')|}],
  headdoor: [%raw {| require('./assets/headdoor.gif')|}],
  reasonconflogo: [%raw {| require('./assets/reasonconflogo.svg')|}],
  reasonconf: [%raw {| require('./assets/reasonconf.jpg')|}],
};

Preloader.load(images);

let s = ReasonReact.string;

let component = ReasonReact.statelessComponent("Show");

let make = (_children) =>{
  ...component,
  render: (_) => {
    <Deck transition=[|Zoom, Slide|] theme transitionDuration=500>
      <Slide transition=[|Zoom|] bgColor="primary">
        <Heading size=1 fit=true caps=true lineHeight=2.0 textColor="black">{js|A la découverte de |js} </Heading>
        <Heading size=1 caps=true>
          <Image width="100%" src=images.reasonlogo />
        </Heading>
      </Slide>
      <Slide
        transition=[|Fade|]
        bgColor="black">
        <Image src=images.me margin="0px auto 40px" />
        <Text textColor="tertiary" textFont="primary">
          "twitter: @_pahann_"
        </Text>
        <Heading size=2 caps=true fit=true textColor="primary" textFont="primary">
          "Patrice Hannotin - Fullstack Developer"
        </Heading>
      </Slide>
      <Slide transition=[|Zoom|] bgColor="primary">
        <Heading size=1 caps=true>
          <Image width="100%" src=images.reasonlogo />
        </Heading>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading caps=true fit=true textColor="tertiary">"Un bug en prod ?!" </Heading>
        <Image width="500px" src=images.headache />
      </Slide>
      <SlideSet>
        <Slide transitionIn=[|Fade|] transitionOut=[|Fade|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">"Un bug, rien que pour vous" </Heading>
          <Appear>
            <CodePane
              lang="javascript"
              source=Examples.reduxProblemActions
              margin="16px auto"
              overflow="overflow"
              textSize="15px"
            />
          </Appear>
          <Appear>
            <CodePane
              lang="javascript"
              source=Examples.reduxProblemReducer
              margin="16px auto"
              overflow="overflow"
              textSize="15px"
            />
          </Appear>
        </Slide>
        <Slide transitionIn=[|Fade|] transitionOut=[|Slide|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">"Un bug, rien que pour vous" </Heading>
          <CodePane
            lang="javascript"
            source=Examples.reduxProblemActions
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
          <CodePane
            lang="javascript"
            source=Examples.reduxProblemReducerThrow
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Slide>
      </SlideSet>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading caps=true fit=true textColor="primary">"Side effect Evil" </Heading>
        <CodePane
          lang="javascript"
          source=Examples.candyFunc
          margin="16px auto"
          overflow="overflow"
          textSize="15px"
        />
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">{js|Perte de temps sous-estimées|js}</Heading>
        <List>
          <Appear><ListItem textColor="primary">(s("Typos"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("Effets de bords"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("Au runtime. (potentiellement en prod)"))</ListItem></Appear>
        </List>
        <Appear>
          <Image width="320px" src=images.nuclear />
        </Appear>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Pour y remédier|js}))</Heading>
        <List>
          <Appear><ListItem textColor="primary">(s("Tests unitaires"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("TypeScript / Flow"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("ImmutableJS"))</ListItem></Appear>
        </List>
      </Slide>
      <Slide transition=[|Zoom|] bgColor="primary">
        <Heading size=1 caps=true>
          <Image width="100%" src=images.reasonlogo />
        </Heading>
      </Slide> 
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="tertiary">(s({js|Once upon a time|js}))</Heading>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Chez Facebook: React... ML !?|js}))</Heading>
        <Image width="400px" src=images.reactlogo />
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">
          (s({js|Chez Bloomberg: BuckleScript|js}))
        </Heading>
        <Image width="300px" src=images.bucklescriptlogo />
        <Text textColor="primary">(s({js|OCaml  ->  JavaScript|js}))</Text>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Le schéma.|js}))</Heading>
        <Image width="600px" src=images.reasonocamljs />
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="tertiary">
          (s({js|On veut du code !|js}))
        </Heading>
      </Slide>
      <SlideSet>
        <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">(s({js|A Reasonnable code|js}))</Heading>
          <CodePane
            lang="javascript"
            source=Examples.reason
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Slide>
        <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">(s({js|A bit more ?|js}))</Heading>
          <CodePane
            lang="javascript"
            source=Examples.welcomers
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Slide>
      </SlideSet>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Records|js}))</Heading>
        <CodePane
          lang="javascript"
          source=Examples.records
          margin="16px auto"
          overflow="overflow"
            textSize="15px"
        />
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Variants|js}))</Heading>
        <CodePane
          lang="javascript"
          source=Examples.variants
          margin="16px auto"
          overflow="overflow"
          textSize="15px"
        />
      </Slide>
      <SlideSet>
        <Slide transitionIn=[|Slide|] transitionOut=[|Fade|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">(s({js|Pattern Matching|js}))</Heading>
          <CodePane
            lang="javascript"
            source=Examples.patmat
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Slide>
        <Slide transitionIn=[|Fade|] transitionOut=[|Slide|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">(s({js|☛  Pattern Matching  ☚|js}))</Heading>
          <CodePane
            lang="javascript"
            source=Examples.patmat
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Slide>
      </SlideSet>
      <SlideSet>
        <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">(s({js|Revenons au problème|js}))</Heading>
          <CodePane
            lang="javascript"
            source=Examples.reduxProblemActions
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
          <CodePane
            lang="javascript"
            source=Examples.reduxProblemReducer
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Slide>
        <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">(s({js|En Reason please !|js}))</Heading>
          <Appear>
            <CodePane
              lang="reason"
              source=Examples.reReduxProblemActions
              margin="16px auto"
              overflow="overflow"
              textSize="15px"
            />
          </Appear>
          <Appear>
            <CodePane
              lang="reason"
              source=Examples.reReduxProblemReducer
              margin="16px auto"
              overflow="overflow"
              textSize="15px"
            />
          </Appear>
        </Slide>
        <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
          <Heading size=1 caps=true fit=true textColor="primary">(s({js|Un choix exhaustif|js}))</Heading>
          <CodePane
            lang="reason"
            source=Examples.reReduxProblemActionsExhaustive
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
          <CodePane
            lang="reason"
            source=Examples.reReduxProblemReducerFixed
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Slide>
      </SlideSet>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="tertiary">
          (s({js|Ecosystème|js}))
        </Heading>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Bucklescript|js}))</Heading>
        <Appear>
          <CodePane
            lang="reason"
            source=Examples.bucklescript
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Appear>
        <Appear>
          <CodePane
            lang="reason"
            source=Examples.bucklescriptraw
            margin="16px auto"
            overflow="overflow"
            textSize="15px"
          />
        </Appear>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|ReasonReact|js}))</Heading>
        <CodePane
          lang="reason"
          source=Examples.reasonreact
          margin="16px auto"
          overflow="overflow"
          textSize="15px"
        />
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|NPM|js}))</Heading>
        <List>
          <Appear><ListItem textColor="primary">(s({js|bs-express|js}))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s({js|bs-moment|js}))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s({js|reason-apollo|js}))</ListItem></Appear>
        </List>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="tertiary">
          (s({js|PRO/CONS|js}))
        </Heading>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Quelques freins|js}))</Heading>
        <List>
          <Appear><ListItem textColor="primary">(s({js|Communauté encore jeune|js}))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s({js|Apprentissage de nouveaux concepts|js}))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s({js|Boucle de feedback différente|js}))</ListItem></Appear>
        </List>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Ah ouais trop bien !|js}))</Heading>
        <List>
          <Appear><ListItem textColor="primary">(s({js|Qualité et dev experience !|js}))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s({js|Interopérabilité|js}))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s({js|Compilation ultra rapide|js}))</ListItem></Appear>
        </List>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="tertiary">
          (s({js|On s'y met ?|js}))
        </Heading>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Du bac à sable au projet|js}))</Heading>
        <List>
          <Appear><ListItem textColor="primary">(s("Try ReasonML"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("Codesandox"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("Sketch.sh"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("redex.github.io"))</ListItem></Appear>
        </List>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|Communauté active et effervescente|js}))</Heading>
        <List>
          <Appear><ListItem textColor="primary">(s("Cours egghead.io"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("Podcast ReasonTown"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("Discord ReasonML"))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s("Dojo !"))</ListItem></Appear>
        </List>
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.reasonconf bgDarken=0.75>
        <Image width="400px" src=images.reasonconflogo />
      </Slide>
      <Slide transition=[|Slide|] bgImage=images.city bgDarken=0.75>
        <Heading size=1 caps=true fit=true textColor="primary">(s({js|OUI AUX TYPES AVEC REASON|js}))</Heading>
        <List>
          <Appear><ListItem textColor="primary">(s({js|Non aux typos !|js}))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s({js|Enjoy <3|js}))</ListItem></Appear>
          <Appear><ListItem textColor="primary">(s({js|Merci !|js}))</ListItem></Appear>
          <Appear><ListItem textColor="tertiary">(s({js|Présentation écrite en ReasonReact (bs-spectacle)|js}))</ListItem></Appear>
        </List>
      </Slide>
      <Slide transition=[|Spin, Slide|] bgColor="tertiary">
        <Heading size=1 caps=true fit=true lineHeight=1.5 textColor="primary">
          (s("Questions ?"))
        </Heading>
        <Image width="600px" src=images.questions />
      </Slide>
    </Deck>
  }
};
