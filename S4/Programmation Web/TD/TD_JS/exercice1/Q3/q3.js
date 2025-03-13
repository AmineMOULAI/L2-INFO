let n = Math.floor(Math.random() * 100);
let v;

do {
    v = parseInt(prompt("Entrer la valeur"));
    if(v == n) alert("Gagné !");
    else if (v > n)alert("Plus petit !");
    else alert("Plus grand !");     
} while (v != n);


    