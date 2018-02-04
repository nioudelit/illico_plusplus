
uniform mat4 modelViewProjectionMatrix;

attribute vec4 position;
attribute vec2 texcoord;
varying vec2 varyingtexcoord;

void main()
{
    varyingtexcoord = vec2(texcoord.x, texcoord.y);
    gl_Position = modelViewProjectionMatrix * position;
}
