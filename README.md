# PASSWORD MANAGER

Trying Zero Knowledge Architecture
This is a free password manager which syncs across devices and also is very secure.

Made with C++ with CMake.

## Current version: 0.03

Still Fiddling around CMake, and created a <b>Argon2i</b> single threaded master password checker.<br>
Standardizing/Prettifying code along with learning System design with C++ is a lengthy process so this project will definitely take a long time. [sharing class/object among files]

## PLAN / DESIGN

1) Platform Independent UI (UI might be shifted to python or so) and Business Logic using C++.
2) A server to handle syncs without any delay and for downloading/updating the app and also storing intermediate stage syncs temporarily using C++.
3) [A feature to have] - Changing passwords every 3 - 6 months and monitoring data leak from any of the saved website so that password can be changed.
4) Using Industry Standard <b>Argon2id</b> for master password.
5) ALWAYS FREE TO USE AND VERY SECURE .