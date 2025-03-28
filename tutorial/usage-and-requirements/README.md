<p align="center">
<img src="https://dwm.suckless.org/dwm.svg" alt="dwm Logo"/>
</p>
<p> &emsp; </p>


<h1>Configuration and requirements</h1>
High level overview of the components needed to run a window manager.<br />
<p> &emsp; </p>



<h2>Video Demonstration</h2>

- ### [General configuration and requirements](https://youtu.be/HCPocmOGnw4)
<p> &emsp; </p>


<h2>Requirements</h2>

- window manager
- terminal emulator
- shell
- file manager
- text editor
<p> &emsp; </p>


<h2>Operating Systems Used </h2>

- Arch Linux
<p> &emsp; </p>


<h2>Configuration Steps</h2>

<p>
<img src="https://i.imgur.com/JGPzRXV.png" height="80%" width="80%" alt="suckless"/>
</p>
<p>
- Navigate to the suckless website and find the patches link in the dwm subsection.<p></p>
- Save the .diff file for the patch you want into your dwm source directory.<p></p>
- Inside the dwm directory run "patch -p1 < (filename.diff)" to apply the patch. (-p1 means use current directory.)<p></p>
</p>
<br />
