//
//  View2.swift
//  ventanas
//
//  Created by roger on 10/02/25.
//

import SwiftUI

struct View2: View {
    var body: some View {
        VStack {
            Text("Hola desde el Navigation View")
            
            NavigationLink(destination: View3()){
                Text("Ir al view 3")
            }
        }
        .navigationTitle("Ajustes")
        .navigationBarTitleDisplayMode(.large)
    }
}

#Preview {
    View2()
}
