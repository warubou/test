

void VSMain(in float4 inPos   : POSITION,
            out float4 outPos : SV_POSITION)
{
    outPos = inPos;
}

void PSMain(in float4 pos    : SV_POSITION,
            out float4 color : SV_Target)
{
    color = float4(1.0f, 1.0f, 1.0f, 1.0f);
}