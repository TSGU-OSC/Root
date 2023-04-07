package my.code.app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Scanner;

public class App {
    private  final String url = "jdbc:mysql://127.0.0.1:3306";
    private  final String username = "root";
    private  final String password = "123456789";
    private Connection connection;
    private Statement statement;
    public App(){
        try{
            connection = DriverManager.getConnection(url,username,password);
            statement = connection.createStatement();
        }catch (Exception e){
        }
    }

    public static void main(String[] args) throws Exception{
        Scanner scanner = new Scanner(System.in);
        String operation ="";
        App app =new App();
        while(!operation.equals("exits")){
            operation =scanner.nextLine();
            if(operation.equals("login")||operation.equals("register")){
                System.out.println("plz enter username: ");
                String username = scanner.nextLine();
                System.out.println("plz enter password: ");
                String password = scanner.nextLine();
                if(operation.equals("login")){
                    app.login(username,password);
                }else{
                    app.register(username,password);
                }
            }else if(operation.equals("show data")){
                app.accountData();
            }
        }

    }

    public void register(String username,String password)throws Exception{
        String use="use test";
        String sql = """
                CREATE TABLE IF NOT EXISTS accountManager( 
                                username varchar(20),
                                password varchar(20) 
                                )charset=utf8
                """;
        String insert = "insert into accountManager(username,password) values"+"('"+username+"','"+password+"')";
        statement.executeUpdate(use);
        statement.executeUpdate(sql);
        int i=statement.executeUpdate(insert);
        if(i>0){
            System.out.println("register complete!");
        }else{
            System.out.println("register fail plz check your input!");
        }

    }

    public void accountData()throws Exception{
        String sql ="use test";
        String show = "select * from accountManager";
        statement.executeUpdate(sql);
        ResultSet resultSet= statement.executeQuery(show);
        System.out.println("username"+"\t"+"password");
        while(resultSet.next()){
            System.out.println(resultSet.getString("username")+"\t"+resultSet.getString("password"));
        }
    }

    public void login(String username,String password)throws Exception{
        String use ="use test";
        String sql="select password from accountManager where username="+"'"+username+"'";
        statement.executeUpdate(use);
        ResultSet resultSet= statement.executeQuery(sql);
        resultSet.next();
        if(resultSet.getString("password").equals(password)){
            System.out.println("welcome "+username);
        }else {
            System.out.println("invalid username or password!");
        }
    }

}
