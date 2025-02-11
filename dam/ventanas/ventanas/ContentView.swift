//
//  ContentView.swift
//  ventanas
//
//  Created by roger on 10/02/25.
//

import SwiftUI

struct ContentView: View {
    @State var showSheet: Bool = false
    var body: some View {
        NavigationView {
            VStack {
                Button(action: { showSheet.toggle() }) {
                    Text("Abrir ventana")
                }

                NavigationLink(destination: View2()) {
                    Text("Navegar")
                }
            }
            .padding()
            .navigationTitle("Inicio")
        }.fullScreenCover(isPresented: $showSheet) {
            ModalView()
        }

    }
}

#Preview {
    ContentView()
}
