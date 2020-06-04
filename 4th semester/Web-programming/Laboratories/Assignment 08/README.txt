Develop a web application based on ASP .NET.

Documentation can be found at:
1) http://www.cs.ubbcluj.ro/~forest/wp
2) http://www.w3schools.com/aspnet
3) http://www.w3schools.com/ajax
All web pages should be accessible only if the user logs in using a username and a password (create a session each time a user logs in, and destroy the session when the user logs out). Have in mind the user experience when you implement the problem:

add different validation logic for input fields
do not force the user to input an ID for an item if he wants to delete/edit/insert it; this should happen automatically (e.g. the user clicks an item from a list, and a page/modal prepopulated with the data for that particular item is opened, where the user can edit it)
add confirmation when the user deletes/cancels an item
do a bare minimum CSS that at least aligns the various input fields

Problem:
Write a web application which implements a guest book. A guest book record is identified by: author (email), title, comment, date. A client of the application should be able to add new entries in the guest book, but only the administrator of the site can delete or modify them. Also the administrator should be able to browse the list of guest book entries based on (grouped by) their author and title using AJAX. Guest book browsing should be paged - entries are displayed on pages with maximum 4 entries on a page (you should be able to go to the previous and the next page).