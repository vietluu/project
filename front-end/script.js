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
 var modar = document.querySelector('form');
 window.onclick = function(event) {

     if (event.target = modal) {
         modal.style.display = "none";
     }

 }
 window.onkeydown = function(event) {
     if (event.keyCode == 27) {
         document.getElementById('form').style.display = "none";
     }
 };

 function show() {


     document.getElementById('passw').type = "text";
     document.getElementById("eye").style.display = "none";
     document.getElementById('neye').style.display = "block";
 }

 function hide() {
     document.getElementById('passw').type = "password";
     document.getElementById('neye').style.display = "none";
     document.getElementById("eye").style.display = "block";

 }