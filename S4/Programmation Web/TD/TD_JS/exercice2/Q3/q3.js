function moyenne(tab)
{
    var m = 0.0;
    for (let i = 0; i < tab.length; i++) m += tab[i];

    return(m / tab.length);
}

function ecart_type(tab)
{
    var m = moyenne(tab);
    var e = 0.0;

    for (let i = 0; i < tab.length; i++) {
        e += (tab[i] - m)*(tab[i] - m);
    }
    e = Math.sqrt(e / tab.length);
    return(e);
}

var n = parseInt(prompt("Entrer n :"));
var t = [];

for (let i = 0; i < n; i++) {
    t[i] = parseFloat(prompt("Entrer " + i));
}
var e = ecart_type(t);
alert("Ecart type : " + e.toFixed(2));

