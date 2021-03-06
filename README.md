# S.T.A.R.S.E.T-Game-Engine

***a Pure 2D Game engine made in C / CSFML made in less than 2000 line.***

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/df589a9f387f444596ee268775fe2930)](https://app.codacy.com/manual/Fosowl/S.T.A.R.S.E.T-Game-Engine?utm_source=github.com&utm_medium=referral&utm_content=Fosowl/S.T.A.R.S.E.T-Game-Engine&utm_campaign=Badge_Grade_Dashboard)
[![Build Status](https://travis-ci.org/Fosowl/S.T.A.R.S.E.T-Game-Engine.svg?branch=master)](https://travis-ci.org/Fosowl/S.T.A.R.S.E.T-Game-Engine)

- [Installation](#Installation)
- [Features](#Features)
- [Docs](#Docs)
- [Contributing](#Contributing)
- [Support](#Support)

 :warning: If you are an EPITA, EPITECH, or 42 student using this for csfml project will result in a -42 unless you become a contributor for this project.

## Installation

  Option 1 :arrow_right: test the engine

  ```

      1. clone this repositorie :

      git clone https://github.com/Fosowl/S.T.A.R.S.E.T-Game-Engine.git

      2. compilation :

      make clean ; make re ; ./test

  ```

  option 2 :arrow_right: import to your project

  ```

      1. clone this repo :

    git clone https://github.com/Fosowl/S.T.A.R.S.E.T-Game-Engine.git

      2. import to your project

      cp -r ./S.T.A.R.S.E.T-Game-Engine/engine <path to your repo>/engine

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

[![add-correct.gif](https://s6.gifyu.com/images/add-correct.gif)](https://gifyu.com/image/luYz)

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

[![democlasss.jpg](https://s6.gifyu.com/images/democlasss.jpg)](https://gifyu.com/image/lvMl)

**Collision system** :label:

```
All collision are detected beetween entities if "is_trigger" is false (false by default),
collison are handled using real life formula for realistic effect.
```
[![collide.gif](https://s6.gifyu.com/images/collide.gif)](https://gifyu.com/image/lkJm)

```
mouse hovering an entitie is detected too
```

**Destruction system** :label:

```
each entitie can be destroy during runtime, you can also destroy all entities when you stop using them.
```

[![destroy.gif](https://s6.gifyu.com/images/destroy.gif)](https://gifyu.com/image/lkJL)

**Binaural sound effect** :label:

```
Each entitie can emit a sound witch is hear in the relative direction beetween the entitie and the player,
 player entitie must be named "player" and declared before other entities that make sound in order for the binaural effect system to work + also make sure the sound is mono and not stereo.
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

  second way :arrow_right: issue, report bug :beetle: or make a suggestion.

## Support


  <a href="https://discord.gg/tJwAGq" target="_blank"><strong>Discord</strong></a>
