# Preparació de la Raspberry Pi 3

```sh
sudo apt-get install qtcreator
# OpenGL experimental
sudo apt-get install xcompmgr libgl1-mesa-dri
```

Per al funcionament d'OpenGL: `raspi-config` → *Advanced Options* → activar *GL Driver*.

`speedQT.pro` és el fitxer de projecte generat amb `qmake` a la Raspberry (inclou `QT += network`).
