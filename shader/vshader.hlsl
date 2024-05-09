#include "shaderHeader.hlsli"

VSOutput VSMain(VSInput vsIn)
{
    VSOutput vsOut;
    vsOut.position = vsIn.position;
    vsOut.worldPos = vsOut.position;
    vsOut.uv = vsIn.uv;
    
    return vsOut;
}