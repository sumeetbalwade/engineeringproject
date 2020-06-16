
import 'package:flutter/material.dart';


void main(List<String> args) {
  runApp(myApp());
}

class myApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        title: 'first app',
        theme: ThemeData(
          primarySwatch: Colors.red,

        ),
        home: Scaffold(
          appBar: AppBar(
            title: Text('first app'),
          ),
          body: Center(
            child: Text(
              'hello its sumeet'
            ),
          ),
        ),    
    );
  }
}