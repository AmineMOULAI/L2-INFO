var puzzle = document.getElementById("container");
var imgs = puzzle.querySelectorAll("div");
var imgSelected = 0;
imgs.forEach((div) => {
    div.addEventListener("click", () => {
        if (div.style.border === "3px solid blue") {
            div.style.border = "none";
            console.log("Deselected!");
            imgSelected -= 1;
        } else if(imgSelected <= 2 && div.style.border != "3px solid blue") {
            div.style.border = "3px solid blue"; 
            console.log("Selected!");
            imgSelected += 1;
        }
    });
});
