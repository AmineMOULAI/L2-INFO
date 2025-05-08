var p = document.querySelector("p");

var b = document.getElementById("mauvais");
b.addEventListener("click", (event) => {
    p.textContent = "il fait mauvais!"
})

var b1 = document.getElementById("beau");
b1.addEventListener("click", (event) => {
    p.textContent = "Il fait beau!"
})

var b2 = document.getElementById("couleur");
b2.addEventListener("click", (event) => {
    p.style.color = "red";
})

