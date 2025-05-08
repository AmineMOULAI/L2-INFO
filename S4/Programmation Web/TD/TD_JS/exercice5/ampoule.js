var b = document.getElementById("boutonA");
var image = document.querySelector("img");
var text = document.querySelectorAll("p");

b.addEventListener("click", (event) =>{
    image.src = "ampoule-fil-allumee.png"
    text.forEach((element) => {
        element.style.backgroundColor = "white";
        element.style.color = "black";
    })
})

var b1 = document.getElementById("boutonE");
b1.addEventListener("click", (event) =>{
    image.src = "ampoule-fil-eteinte.png"
    text.forEach((element) => {
        element.style.backgroundColor = "Black";
        element.style.color = "White";
    })
})