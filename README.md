# Illico.

## Un bidouciel de la râcle pour la performance visuelle en direct

L'*illico* est un *bidouciel* (un logiciel de la râcle) qui a été bricolé pour pouvoir faire de la peformance vidéo, proche du VJ. L'*illico* n'est ni plus ni moins qu'un sampler (ou boucleur) d'images capturées par un flux vidéo (webcam). À la différence des logiciels de VJ comme Résorhume Halena, c'est que les images sont à faire en direct, sur scène (un petit peu comme "Science of Garbage" de Pierre Hebert et Bob Ostertag, merci à Y.V.S de me l'avoir signalé). Le principe n'est pas plus inédit que les inventions précinématrographique du 19eme siècle comme le kinétoscope, mais bon ça peut-être que vous vous en foutez.

Initialement codé avec Processing, il passe en C++ (avec OpenFrameworks) pour gagner en force et robustesse. Avé.

## Installation

### MAC

Télécharger le programme. Si cela ne fonctionne pas, il faudra compiler le programme directement sur votre ordinateur. [en rédaction]

### Linux et cie

Télécharger le programme. Si cela ne fonctionne pas, il faudra compiler le programme directement sur votre ordinateur.  [en rédaction]

#### Raspberry pi

À voir selon optimisation [en rédaction]

- https://github.com/openFrameworks-arm/Resonate2013Workshop
- https://forum.openframeworks.cc/t/shaders-examples-not-working-on-rpi-with-of-0-9-7/25896
- https://projects.drogon.net/raspberry-pi/wiringpi/
- http://codelab.fr/6814

linux uvcdynctrl


### Windows (Explications temporaires).

Télécharger le programme. Si cela ne fonctionne pas, bin… tant pis. [en rédaction]

## Lancer et paramétrer le programme

### 1. Version Processing

1. Installer Processing
2. Télécharger le code
3. Renommer illico-master en illico
4. ouvrir illico.pde avec Processing
5. Vérifier l'identifiant de la webcam en modifiant la ligne (aux alentours de la ligne n°20).

```
cam = new Capture(this, cameras[15]);
```
Et remplacez par un numéro qui correspond à la webcam branchée (voir résultats console).

### 2. Version C++

[en rédaction]

## Utilisation et commandes

### 1. Version Procesing

- Souris: Sélectionner la teinte de vert à incruster.
- Barre espace: Afficher flux webcam
- Touches de a à u: Afficher/Cacher les samples d'images.
- Touches de a à u + MAJ: Capturer une image
- Alt: active/Désactive le mode de suppresion des samples, une fois activée, il suffit d'appuyer sur les touches de samples à effacer.

### 2. Version C++

 [en rédaction]
 
## Enregistrer une performance

 [en rédaction].
 
 ## Algorithmes et GLSL
 
 [en rédaction], vesion openGL

