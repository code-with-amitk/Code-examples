## System Call vs Normal Call

||System Call|Normal Call|
|---|---|---|
|What|Call into kernel, done using calling interrupt.|fun(), which does not go to kernel for processing|
|Speed|Bcoz of mode switching from user to kernel|comparably fast
|How|calls [trap instruction](/Motherboard/CPU/Memory/Virtual_Physical_Memory/Terms.md)|calls call instruction|
