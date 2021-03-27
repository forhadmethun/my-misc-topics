### Servlet
 - When we request for a dynamic webpage it goes to the server and server hands back the request to helper application - Web Container(tomcat, glassfish, etc).
 - The web container contains special file named deployment descriptor which is web.xml file which basically contains that for which request which servlet need to be called. 
 - Servlet is basically java class which take request form the client and process the request and provide response in html page. The web.xml file contains two tags - servlet(servlet name), servlet-mapping(contains the url pattern). 
 - A Servlet java file extends the HttpServlet class which provides all the functionality needed.
 - Inside the Servlet we need to override service() method which contains two parameter - HttpServletRequest req, HttpServletResponse res. we can response string data with PrintWriter class of Java.
   - HttpServletRequest contains all data that client send to server and HttpServletResponse cotains vice versa.
 - other method exists like doGet(), doPost()
 - request can be send from one servet to another servlet with RequestDispatcher class and sendRedirect
   - rd works fine withine one domain but for different domain cleint need to know that something is happenning so sendRedirect comes in handy 
 - ServletContext, ServletConfig can read data from specific tag of web.xml file 
 - A jsp page by defaults contains request which is called  implicit object 
   - JPS page converted to Servlet  
   - JSP page contains -
     - directive (import statements)
       - @page
       - @include
       - @taglib
     - declaration( outside method or property of service method)
     - scriplet<%  %>
     - expression <%=blahblh>
   - Builtin Object
     - request
     - response
     - pageContext
     - out
     - session
     - application
     - config

- Filter can be come in handy for controlling request. Because request goes to filter first and then after filtering it hands back to the servlet








POJO ( Plain Old Java Object)