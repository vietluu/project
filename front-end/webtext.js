var slideIndex = 0;
showSlides();

function showSlides() {
    var i;
    var slides = document.getElementsByClassName("slide");

    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }
    slideIndex++;
    if (slideIndex > slides.length) { slideIndex = 1 }

    slides[slideIndex - 1].style.display = "block";

    setTimeout(showSlides, 5000);
}
var Index = 1;
showSlider(Index);

function plusSlider(n) {
    showSlider(Index += n);
}

function currentSlider(n) {
    showSlider(Index = n);
}

function showSlider(n) {
    var i;
    var slider = document.getElementsByClassName("slide");

    if (n > slider.length) { Index = 1 }
    if (n < 1) { Index = slider.length }
    for (i = 0; i < slider.length; i++) {
        slider[i].style.display = "none";
    }

    slider[Index - 1].style.display = "block";

}