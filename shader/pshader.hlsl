#include "shaderHeader.hlsli"

Texture2D<float4> g_Texture : register(t0);
SamplerState g_Sampler : register(s0);

float4 PSMain(VSOutput vsOut) : SV_TARGET
{
    return float4(g_Texture.Sample(g_Sampler, vsOut.uv));
}