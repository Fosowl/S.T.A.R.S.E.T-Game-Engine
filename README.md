# S.T.A.R.S.E.T-Game-Engine

***a Pure 2D Game engine made in C / CSFML made in less than 2000 line.***

- [Installation](#installation)
- [Features](#features)
- [Docs](#faq)
- [Contributing](#contributing)
- [Support](#support)

## Installation

  Option 1 :arrow_right: test the engine

  ```

      1. clone this repositorie :

      git clone https://github.com/Fosowl/S.T.A.R.S.E.T-Game-Engine.git

      2. compilation :

      make clean ; make re

  ```

  option 2 :arrow_right: import to your project

  ```

      1. clone this repo :

    git clone https://github.com/Fosowl/S.T.A.R.S.E.T-Game-Engine.git

      2. import to your project

      cp -r ./S.T.A.R.S.E.T-Game-Engine/engine <pth to your repo>/engine

      3. call engine Makefile from your makefile 🔨

  $(BIN_NAME):
                  @cd $(ENGINE_DIR) ; make
                  @gcc -o $(BIN_NAME) $(SRC) $(ENGINE_DIR)/$(ENGINE_NAME) $(CFLAGS)
  ```

## Features

**Easy to add entities** :label:

```
It's easy to add entities !
```

[![add_engine.gif](https://s4.gifyu.com/images/add_engine.gif)](https://gifyu.com/image/lEEJ)

**Easy Animation system** :label:

```
animation can be set and play in very few line...
```

[![animation_engine.gif](https://s4.gifyu.com/images/animation_engine.gif)](https://gifyu.com/image/lEht)

**Easy Movement system** :label:

```
entities can be teleported, follow a point, or follow another entities.
```

[![move_engine.gif](https://s6.gifyu.com/images/move_engine.gif)](https://gifyu.com/image/lkyU)

**Class and name system** :label:

```
each entities have a name and can also have a class,
witch alow you to select multiple entities of the same class at the same time.
```

**Collision system** :label:

```
All collision are detected beetween entities if "is_trigger" is false (false by default),
collison are handled using real life formula for realistic effect.
```
[![collide.gif](https://s6.gifyu.com/images/collide.gif)](https://gifyu.com/image/lkJm)

```
mouse hovering an entities is detected too
```

**Destruction system** :label:

```
each entities can be destroy during runtime, you can also destroy all entities when you stop using them.
```

[![destroy.gif](https://s6.gifyu.com/images/destroy.gif)](https://gifyu.com/image/lkJL)

**Binaural sound effect** :label:

```Each entities can emit a sound witch is hear in the relative direction beetween the entities and the player,
 player entities must be named "player" in order for this system to work.
```
[![sound_engine.gif](https://s6.gifyu.com/images/sound_engine.gif)](https://gifyu.com/image/lkyf)

**Component system** :label:

   :warning: ```Component system is Under devellopement  ```

## Docs

 <a href="https://github.com/Fosowl/S.T.A.R.S.E.T-Game-Engine/wiki" target="_blank"><strong>Docs main page</strong></a>

## Contributing 🔃

  first way :arrow_right: pull request :
 
    1. fork this repo 🍴.

    2. clone your forked repo.

    3. make change with your favorite editor.

    4. make a pull request, I will check when I have time ;)

  second way :arrow_right: issue, report bug :beetle: and make suggestion :
      go to "issue" and report an issue.

## Support

  **mail :** martin.legrand@epitech.eu (please use github for pull request and "issue" to report problem).

  <a href="" target="_blank"><strong>Discord</strong></a>
