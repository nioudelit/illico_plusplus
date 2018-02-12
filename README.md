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

Pour qu'illico fonctionne sur un Raspberry Pi, il faut faire quelques changements:

Main.cpp (la version openGL est différente sur une raspberry):

```
#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    
    ofGLESWindowSettings settings;
    
    settings.glesVersion = 2;
    settings.width = 800;
    settings.height = 480;
    settings.setPosition(ofVec2f(300,0));
    ofCreateWindow(settings);

    ofRunApp(new ofApp());

}
```
Ce qui implique qu'il faudra aussi modifier les fichiers GLSL:

test.vert:

```
uniform mat4 modelViewProjectionMatrix;

attribute vec4 position;
attribute vec2 texcoord;
varying vec2 varyingtexcoord;

void main()
{
    varyingtexcoord = vec2(texcoord.x, texcoord.y);
    gl_Position = modelViewProjectionMatrix * position;
}
```
test.frag:

```
precision highp float;

// Recevoir Texture via OF
uniform sampler2D tex0;
uniform float h;
uniform float s;
uniform float b;

//Position envoyees par le vertex shader
varying vec2 varyingtexcoord;

//Notre fragment haut en couleurs
//out vec4 outputColor;

vec3 rgb2hsv(vec3 c){
    //https://stackoverflow.com/questions/15095909/from-rgb-to-hsv-in-opengl-glsl

    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));

    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

void main(){

	vec4 col = texture2D(tex0, varyingtexcoord);
	vec3 vertReference = vec3(0.0, 1.0, 0.0);
	vertReference = rgb2hsv(vertReference);

	vec3 texColorHSB = rgb2hsv(col.xyz);
	if(distance(texColorHSB.x, vertReference.x) <= h && 
	   distance(texColorHSB.y, vertReference.y ) <= s &&
	   distance(texColorHSB.z, vertReference.z) >= b)
        	discard;
	
	gl_FragColor = vec4(col);

	//float somme = col.r + col.g + col.b;
	//float bright = somme * 0.33333;
	//outputColor = vec4(vec3(bright), col.a);
}
```

