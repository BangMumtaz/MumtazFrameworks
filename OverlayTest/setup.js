const fs2=require("fs");
const d="c:/Users/dwisa/source/repos/MumtazWorks/OverlayTest";
const img="c:/Users/dwisa/source/repos/MumtazWorks/MumtazWorks/deps/imgui";
function w(f,c){fs2.writeFileSync(d+"/"+f,c);console.log(f+" "+c.length+" bytes");}
