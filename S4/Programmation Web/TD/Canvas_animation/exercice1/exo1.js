function rand_color()
{
    const nr = Math.floor(Math.random() * 256);
    const ng = Math.floor(Math.random() * 256);
    const nb = Math.floor(Math.random() * 256);

    return("rgb(("+ nr + "), (" + ng +"), ("+ nb + "))");
}

var n = parseInt(prompt("Entrer le nombre de rectangles : "));
