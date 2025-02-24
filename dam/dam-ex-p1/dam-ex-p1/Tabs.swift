//
//  Tabs.swift
//  dam-ex-p1
//
//  Created by roger on 21/02/25.
//

import SwiftUI

struct Tabs: View {
    @Binding var info: Info
    @Binding var showLogin: Bool
    var body: some View {
        TabView {
            Tab("Home", systemImage: "house") {
                Home(user: info.user)
            }
            Tab("Usuario", systemImage: "profile") {
                Usuario(info: $info, showLogin: $showLogin)
            }
        }
    }
}


#Preview {
    // Tabs(user: "admin")
}
