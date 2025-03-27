var m1 = document.querySelector("#container1");
var m2 = document.querySelector("#container2");
var sm1 = document.querySelector("#sous-menu1");
var sm2 = document.querySelector("#sous-menu2");



function hideMenu()
{
    sm1.style.display = 'none';
    sm2.style.display = 'none';
}

function showMenu(menu)
{
    menu.style.display = 'flex';
}

hideMenu();

m1.addEventListener("mouseover", () => {
    showMenu(sm1);
});


m1.addEventListener("mouseleave", () => {
    hideMenu(sm1);
});
