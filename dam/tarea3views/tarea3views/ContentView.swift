//
//  ContentView.swift
//  tarea3views
//
//  Created by roger on 10/02/25.
//

import SwiftUI

struct ContentView: View {
    // @State selectedView = 0
    var body: some View {
        VStack {
            TabNavigation()
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
