//
//  TabNavigation.swift
//  tarea3views
//
//  Created by roger on 10/02/25.
//

import SwiftUI

struct TabNavigation: View {
    var body: some View {
        TabView {
            View1()
                .tabItem {
                    Label("Tab 1", systemImage: "globe")
                }
            View2()
            .tabItem {
                    Label("Tab 2", systemImage: "pc")
                }
            View3()
                .tabItem {
                    Label("Tab 3", systemImage: "house")
                }
        }
    }
}

#Preview {
    TabNavigation()
}
