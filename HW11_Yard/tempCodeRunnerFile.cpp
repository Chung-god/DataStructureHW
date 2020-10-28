    for(int i = 0; i < sv.size(); i++){
        for(int j = 0; j <= sv[i].size();j++){
            cout<<sv[i].top()<<" ";
            sv[i].pop();
        }
        cout<<"\n";
    }