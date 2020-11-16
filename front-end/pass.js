var mybt = document.getElementById('top');
window.onscroll = function() {
    scoll()
};

function scoll() {

    if (document.documentElement.scrollTop > 50 || document.body.scrollTop > 50) {
        mybt.style.display = "block";
    } else {
        mybt.style.display = "none";
    }

}

function myfunction() {
    window.scrollTo(0, 0);

}